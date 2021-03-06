#include <awl/exception.hpp>
#include <awl/backends/linux/timerfd/object.hpp>
#include <awl/backends/posix/duration.hpp>
#include <awl/timer/setting.hpp>
#include <fcppt/text.hpp>
#include <fcppt/assert/error.hpp>
#include <fcppt/config/external_begin.hpp>
#include <time.h> // NOLINT(hicpp-deprecated-headers,modernize-deprecated-headers)
#include <unistd.h>
#include <sys/timerfd.h>
#include <chrono>
#include <fcppt/config/external_end.hpp>


awl::backends::linux::timerfd::object::object()
:
	fd_{
		::timerfd_create(
			CLOCK_MONOTONIC,
			0
		)
	}
{
	if(
		fd_.get()
		==
		-1
	)
	{
		throw
			awl::exception{
				FCPPT_TEXT("timerfd_create failed")
			};
	}
}


awl::backends::linux::timerfd::object::~object()
{
	::close(
		fd_.get()
	);
}

awl::backends::posix::fd
awl::backends::linux::timerfd::object::get() const
{
	return
		fd_;
}

void
awl::backends::linux::timerfd::object::set_time(
	awl::timer::setting const &_setting
)
{
	auto const convert_time(
		[](
			awl::backends::posix::duration const _duration
		)
		->
		timespec
		{
			return
				timespec{
					std::chrono::duration_cast<
						std::chrono::seconds
					>(
						_duration
					).count(),
					std::chrono::duration_cast<
						std::chrono::nanoseconds
					>(
						_duration
						%
						std::chrono::duration_cast<
							awl::backends::posix::duration
						>(
							// NOLINTNEXTLINE(fuchsia-default-arguments-calls)
							std::chrono::seconds(
								1
							)
						)
					).count()
				};
		}
	);

	itimerspec const time_spec{
		convert_time(
			_setting.period().get()
		),
		// A delay of 0 makes the timer inactive,
		// so use the smallest delay possible instead.
		convert_time(
			_setting.delay().get()
			==
			// NOLINTNEXTLINE(fuchsia-default-arguments-calls)
			awl::timer::duration{
				0
			}
			?
				// NOLINTNEXTLINE(fuchsia-default-arguments-calls)
				awl::timer::duration{
					1
				}
			:
				_setting.delay().get()
		)
	};

	if(
		::timerfd_settime(
			fd_.get(),
			0,
			&time_spec,
			nullptr
		)
		!=
		0
	)
	{
		throw
			awl::exception{
				FCPPT_TEXT("timerfd_settime failed")
			};
	}
}

awl::backends::linux::timerfd::object::value_type
awl::backends::linux::timerfd::object::read()
{
	value_type ret{0};

	FCPPT_ASSERT_ERROR(
		::read(
			fd_.get(),
			&ret,
			sizeof(
				value_type
			)
		)
		==
		static_cast<
			ssize_t
		>(
			sizeof(
				value_type
			)
		)
	);

	return
		ret;
}

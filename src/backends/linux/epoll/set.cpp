#include <awl/exception.hpp>
#include <awl/backends/linux/epoll/ctl.hpp>
#include <awl/backends/linux/epoll/fd_vector.hpp>
#include <awl/backends/linux/epoll/set.hpp>
#include <awl/backends/posix/duration.hpp>
#include <awl/backends/posix/fd.hpp>
#include <awl/backends/posix/optional_duration.hpp>
#include <fcppt/const.hpp>
#include <fcppt/make_int_range_count.hpp>
#include <fcppt/text.hpp>
#include <fcppt/algorithm/map_optional.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/cast/truncation_check.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/config/external_begin.hpp>
#include <sys/epoll.h>
#include <chrono>
#include <fcppt/config/external_end.hpp>


awl::backends::linux::epoll::set::set()
:
	epoll_fd_(),
	events_()
{
}

awl::backends::linux::epoll::set::~set()
{
}

void
awl::backends::linux::epoll::set::add(
	awl::backends::posix::fd const _fd
)
{
	events_.push_back(
		epoll_event()
	);

	awl::backends::linux::epoll::ctl(
		epoll_fd_,
		_fd,
		&events_.back()
	);
}

void
awl::backends::linux::epoll::set::remove(
	awl::backends::posix::fd const _fd
)
{
	awl::backends::linux::epoll::ctl(
		epoll_fd_,
		_fd,
		nullptr
	);

	events_.pop_back();
}

awl::backends::linux::epoll::fd_vector
awl::backends::linux::epoll::set::epoll(
	awl::backends::posix::optional_duration const &_opt_duration
)
{
	int const ret(
		::epoll_wait(
			epoll_fd_.get().get(),
			events_.data(),
			fcppt::cast::size<
				int
			>(
				fcppt::cast::to_signed(
					events_.size()
				)
			),
			fcppt::optional::maybe(
				_opt_duration,
				fcppt::const_(
					-1
				),
				[](
					awl::backends::posix::duration const _duration
				)
				{
					return
						fcppt::cast::truncation_check<
							int
						>(
							std::chrono::duration_cast<
								std::chrono::milliseconds
							>(
								_duration
							).count()
						);
				}
			)
		)
	);

	if(
		ret
		==
		-1
	)
		throw
			awl::exception{
				FCPPT_TEXT("epoll_wait failed!")
			};

	unsigned const ready(
		fcppt::cast::to_unsigned(
			ret
		)
	);

	return
		fcppt::algorithm::map_optional<
			awl::backends::linux::epoll::fd_vector
		>(
			fcppt::make_int_range_count(
				ready
			),
			[
				this
			](
				unsigned const _index
			)
			{
				epoll_event const &event(
					this->events_[
						_index
					]
				);

				return
					fcppt::optional::make_if(
						event.events
						&
						EPOLLIN,
						[
							&event
						]{
							return
								awl::backends::posix::fd{
									event.data.fd
								};
						}
					);
			}
		);
}

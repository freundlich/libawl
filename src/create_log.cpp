#include <awl/create_log.hpp>
#include <awl/log_context.hpp>
#include <fcppt/io/clog.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/location.hpp>
#include <fcppt/log/parameters.hpp>


fcppt::log::parameters
awl::create_log(
	fcppt::log::location const &_location
)
{
	return
		fcppt::log::parameters(
			fcppt::io::clog(),
			fcppt::log::level::warning
		)
		.context_location(
			awl::log_context(),
			_location
		)
		.enabled(
			true
		);
}

#include <awl/backends/sdl/timer/object.hpp>
#include <awl/backends/sdl/system/event/original_processor.hpp>
#include <awl/backends/sdl/system/event/processor.hpp>
#include <awl/event/base.hpp>
#include <awl/main/exit_code.hpp>
#include <awl/system/event/result.hpp>
#include <awl/timer/object.hpp>
#include <awl/timer/setting_fwd.hpp>
#include <awl/timer/unique_ptr.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/unique_ptr_to_base.hpp>


awl::backends::sdl::system::event::original_processor::original_processor()
:
	awl::backends::sdl::system::event::processor{},
	timer_events_{}
{
}

awl::backends::sdl::system::event::original_processor::~original_processor()
{
}

awl::system::event::result
awl::backends::sdl::system::event::original_processor::poll()
{
}

awl::system::event::result
awl::backends::sdl::system::event::original_processor::next()
{
}

void
awl::backends::sdl::system::event::original_processor::quit(
	awl::main::exit_code const _code
)
{
}

awl::timer::unique_ptr
awl::backends::sdl::system::event::original_processor::create_timer(
	awl::timer::setting const &_setting
)
{
	return
		fcppt::unique_ptr_to_base<
			awl::timer::object
		>(
			fcppt::make_unique_ptr<
				awl::backends::sdl::timer::object
			>(
				fcppt::make_ref(
					this->timer_events_
				),
				_setting
			)
		);
}

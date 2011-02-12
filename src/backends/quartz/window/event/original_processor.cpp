#include <awl/backends/quartz/window/event/original_processor.hpp>
#include <awl/backends/quartz/window/instance.hpp>

awl::backends::quartz::window::event::original_processor::original_processor(
	quartz::window::instance_ptr const _window
)
:
	window_(_window)
{
}

awl::backends::quartz::window::event::original_processor::~original_processor()
{
}

bool
awl::backends::quartz::window::event::original_processor::dispatch()
{
	return true;
}

fcppt::signal::auto_connection
awl::backends::quartz::window::event::original_processor::resize_callback(
	awl::window::event::resize_callback const &_callback
)
{
	return
		resize_signal_.connect(
			_callback
		);
}

awl::window::instance_ptr const
awl::backends::quartz::window::event::original_processor::window() const
{
	return window_;
}

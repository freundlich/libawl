#include <awl/backends/x11/window/wrapped_instance.hpp>
#include <fcppt/math/dim/basic_impl.hpp>

awl::backends::x11::window::wrapped_instance::wrapped_instance(
	x11::display_ptr const _display,
	x11::screen const _screen,
	Window const _window
)
:
	display_(_display),
	screen_(_screen),
	window_(_window)
{
}

awl::backends::x11::window::wrapped_instance::~wrapped_instance()
{
}

void
awl::backends::x11::window::wrapped_instance::show()
{
}

awl::window::dim const
awl::backends::x11::window::wrapped_instance::size() const
{
}

awl::backends::x11::display_ptr const
awl::backends::x11::window::wrapped_instance::display() const
{
	return display_;
}

awl::backends::x11::screen const
awl::backends::x11::window::wrapped_instance::screen() const
{
	return screen_;
}

awl::backends::x11::visual_ptr const
awl::backends::x11::window::wrapped_instance::visual() const
{
	return visual_ptr();
}

Window
awl::backends::x11::window::wrapped_instance::get() const
{
	return window_;
}


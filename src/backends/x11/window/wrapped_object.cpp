#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/visual/object.hpp>
#include <awl/backends/x11/window/class_hint.hpp>
#include <awl/backends/x11/window/const_optional_class_hint_ref.hpp>
#include <awl/backends/x11/window/get_class_hint.hpp>
#include <awl/backends/x11/window/get_geometry.hpp>
#include <awl/backends/x11/window/rect.hpp>
#include <awl/backends/x11/window/visual.hpp>
#include <awl/backends/x11/window/wrapped_object.hpp>
#include <fcppt/make_cref.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/X.h>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::window::wrapped_object::wrapped_object(
	awl::backends::x11::display & _display,
	awl::backends::x11::screen const _screen,
	Window const _window
)
:
	display_(
		_display
	),
	screen_(
		_screen
	),
	window_(
		_window
	),
	visual_(
		awl::backends::x11::window::visual(
			*this
		)
	),
	class_hint_(
		awl::backends::x11::window::get_class_hint(
			_display,
			_window
		)
	)
{
}

awl::backends::x11::window::wrapped_object::~wrapped_object()
{
}

bool
awl::backends::x11::window::wrapped_object::destroyed() const
{
	return
		false;
}

awl::backends::x11::display &
awl::backends::x11::window::wrapped_object::display() const
{
	return
		display_;
}

awl::backends::x11::screen
awl::backends::x11::window::wrapped_object::screen() const
{
	return
		screen_;
}

awl::backends::x11::visual::object const &
awl::backends::x11::window::wrapped_object::x11_visual() const
{
	return
		*visual_;
}

awl::backends::x11::window::rect
awl::backends::x11::window::wrapped_object::rect() const
{
	return
		awl::backends::x11::window::get_geometry(
			*this
		);
}

Window
awl::backends::x11::window::wrapped_object::get() const
{
	return
		window_;
}

awl::backends::x11::window::const_optional_class_hint_ref
awl::backends::x11::window::wrapped_object::class_hint() const
{
	return
		fcppt::optional::map(
			class_hint_,
			[](
				awl::backends::x11::window::class_hint const &_hint
			)
			{
				return
					fcppt::make_cref(
						_hint
					);
			}
		);
}

#ifndef AWL_BACKENDS_X11_WINDOW_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_OBJECT_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/visual/object.hpp>
#include <awl/backends/x11/window/const_optional_class_hint_ref_fwd.hpp>
#include <awl/backends/x11/window/rect_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/window/object.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{

class AWL_CLASS_SYMBOL object
:
	public awl::window::object
{
	FCPPT_NONCOPYABLE(
		object
	);
protected:
	AWL_DETAIL_SYMBOL
	object();
public:
	AWL_DETAIL_SYMBOL
	~object()
	override;

	virtual
	void
	destroy() = 0;

	virtual
	bool
	destroyed() const = 0;

	virtual
	awl::backends::x11::display &
	display() const = 0;

	virtual
	awl::backends::x11::screen
	screen() const = 0;

	virtual
	awl::backends::x11::visual::object const &
	visual() const
	override = 0;

	virtual
	awl::backends::x11::window::rect
	rect() const = 0;

	virtual
	Window
	get() const = 0;

	virtual
	awl::backends::x11::window::const_optional_class_hint_ref
	class_hint() const = 0;
};

}
}
}
}

#endif

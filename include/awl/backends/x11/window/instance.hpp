#ifndef AWL_BACKENDS_X11_WINDOW_INSTANCE_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_INSTANCE_HPP_INCLUDED

#include <awl/backends/x11/window/event/optional.hpp>
#include <awl/backends/x11/window/class_hint_fwd.hpp>
#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/visual_fwd.hpp>
#include <awl/window/instance.hpp>
#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
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

class AWL_CLASS_SYMBOL instance
:
	public awl::window::instance
{
	FCPPT_NONCOPYABLE(
		instance
	);
protected:
	AWL_SYMBOL
	instance();
public:
	AWL_SYMBOL
	virtual ~instance() = 0;

	virtual
	void
	destroy() = 0;

	virtual
	bool
	destroyed() const = 0;

	virtual x11::display &
	display() const = 0;

	virtual x11::screen const
	screen() const = 0;

	virtual x11::visual const &
	visual() const = 0;

	virtual Window
	get() const = 0;

	// might return 0
	virtual x11::window::class_hint const *
	class_hint() const = 0;
};

}
}
}
}

#endif

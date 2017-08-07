#ifndef AWL_BACKENDS_X11_SYSTEM_EVENT_GENERIC_HPP_INCLUDED
#define AWL_BACKENDS_X11_SYSTEM_EVENT_GENERIC_HPP_INCLUDED

#include <awl/backends/x11/Xlib.hpp>
#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/display_ref.hpp>
#include <awl/backends/x11/system/event/generic_fwd.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/event/base.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace system
{
namespace event
{

class AWL_DETAIL_CLASS_SYMBOL generic
:
	public awl::event::base
{
	FCPPT_NONCOPYABLE(
		generic
	);
public:
	AWL_DETAIL_SYMBOL
	generic(
		awl::backends::x11::display_ref,
		XGenericEventCookie const &
	);

	AWL_DETAIL_SYMBOL
	~generic()
	override;

	AWL_DETAIL_SYMBOL
	XGenericEventCookie const &
	get() const;

	AWL_DETAIL_SYMBOL
	XGenericEventCookie &
	get();

	AWL_DETAIL_SYMBOL
	awl::backends::x11::display &
	display() const;
private:
	awl::backends::x11::display_ref const display_;

	XGenericEventCookie event_;
};

}
}
}
}
}

#endif

#ifndef AWL_BACKENDS_X11_WINDOW_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_OBJECT_HPP_INCLUDED

#include <awl/backends/x11/window/base.hpp>
#include <awl/backends/x11/window/event/mask.hpp>
#include <awl/backends/x11/window/event/type.hpp>
#include <awl/event/connection_unique_ptr.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{

class AWL_DETAIL_CLASS_SYMBOL object
:
	public awl::backends::x11::window::base
{
	FCPPT_NONCOPYABLE(
		object
	);
protected:
	AWL_DETAIL_SYMBOL
	object();
public:
	AWL_DETAIL_SYMBOL
	virtual
	~object() = 0;

	virtual
	awl::event::connection_unique_ptr
	register_event(
		awl::backends::x11::window::event::type
	) = 0;

	virtual
	awl::event::connection_unique_ptr
	add_event_mask(
		awl::backends::x11::window::event::mask
	) = 0;
};

}
}
}
}

#endif

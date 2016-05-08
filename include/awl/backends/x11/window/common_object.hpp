#ifndef AWL_BACKENDS_X11_WINDOW_COMMON_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_COMMON_OBJECT_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/backends/x11/window/class_hint_fwd.hpp>
#include <awl/backends/x11/window/object.hpp>
#include <awl/backends/x11/window/rect_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/window/dim_fwd.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{

class AWL_CLASS_SYMBOL common_object
:
	public awl::backends::x11::window::object
{
	FCPPT_NONCOPYABLE(
		common_object
	);
protected:
	AWL_DETAIL_SYMBOL
	common_object();
public:
	AWL_DETAIL_SYMBOL
	~common_object()
	override;

	AWL_DETAIL_SYMBOL
	void
	show()
	override;

	AWL_DETAIL_SYMBOL
	awl::window::dim
	size() const
	override;

	AWL_DETAIL_SYMBOL
	awl::backends::x11::window::rect
	rect() const
	override;
};

}
}
}
}

#endif

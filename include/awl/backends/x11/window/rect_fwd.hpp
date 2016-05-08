#ifndef AWL_BACKENDS_X11_WINDOW_RECT_FWD_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_RECT_FWD_HPP_INCLUDED

#include <awl/window/unit.hpp>
#include <fcppt/math/box/rect_fwd.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{

typedef
fcppt::math::box::rect<
	awl::window::unit
>
rect;

}
}
}
}

#endif

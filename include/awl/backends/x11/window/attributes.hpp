#ifndef AWL_BACKENDS_X11_WINDOW_ATTRIBUTES_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_ATTRIBUTES_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <X11/Xlib.h>

namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{

AWL_SYMBOL
XWindowAttributes const
attributes(
	Display *,
	Window
);

}
}
}
}

#endif

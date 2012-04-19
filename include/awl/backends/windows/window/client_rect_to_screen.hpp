#ifndef AWL_BACKENDS_WINDOWS_WINDOW_CLIENT_RECT_TO_SCREEN_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_CLIENT_RECT_TO_SCREEN_HPP_INCLUDED

#include <awl/backends/windows/window/object_fwd.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/symbol.hpp>

namespace awl
{
namespace backends
{
namespace windows
{
namespace window
{

AWL_SYMBOL
RECT const
client_rect_to_screen(
	window::object const &,
	RECT const &
);

}
}
}
}

#endif

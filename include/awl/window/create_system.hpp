#ifndef AWL_WINDOW_CREATE_SYSTEM_HPP_INCLUDED
#define AWL_WINDOW_CREATE_SYSTEM_HPP_INCLUDED

#include <awl/window/system_ptr.hpp>
#include <awl/symbol.hpp>

namespace awl
{
namespace window
{

// This function creates a window system that fits the current
// operating system/environment (will create the x11 system in Linux
// and the WinAPI system on windows)
AWL_SYMBOL
window::system_ptr const
create_system();

}
}

#endif

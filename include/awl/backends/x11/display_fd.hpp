#ifndef AWL_BACKENDS_X11_DISPLAY_FD_HPP_INCLUDED
#define AWL_BACKENDS_X11_DISPLAY_FD_HPP_INCLUDED

#include <awl/backends/posix/fd.hpp>
#include <awl/backends/x11/display_fwd.hpp>
#include <awl/detail/symbol.hpp>


namespace awl
{
namespace backends
{
namespace x11
{

AWL_DETAIL_SYMBOL
awl::backends::posix::fd
display_fd(
	awl::backends::x11::display &
);

}
}
}

#endif

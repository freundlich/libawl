#ifndef AWL_BACKENDS_X11_CURSOR_SOURCE_PIXMAP_HPP_INCLUDED
#define AWL_BACKENDS_X11_CURSOR_SOURCE_PIXMAP_HPP_INCLUDED

#include <awl/backends/x11/pixmap/const_holder_ref.hpp>
#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/strong_typedef.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace cursor
{

FCPPT_MAKE_STRONG_TYPEDEF(
	awl::backends::x11::pixmap::const_holder_ref,
	source_pixmap
);

}
}
}
}

#endif

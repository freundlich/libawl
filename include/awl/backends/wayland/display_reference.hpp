#ifndef AWL_BACKENDS_WAYLAND_DISPLAY_REFERENCE_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_DISPLAY_REFERENCE_HPP_INCLUDED

#include <awl/backends/wayland/display_fwd.hpp>
#include <fcppt/reference_impl.hpp>


namespace awl
{
namespace backends
{
namespace wayland
{

typedef
fcppt::reference<
	awl::backends::wayland::display
>
display_reference;

}
}
}

#endif

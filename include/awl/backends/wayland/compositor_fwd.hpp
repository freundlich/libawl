#ifndef AWL_BACKENDS_WAYLAND_COMPOSITOR_FWD_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_COMPOSITOR_FWD_HPP_INCLUDED

#include <awl/backends/wayland/make_registry_object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <wayland-client-protocol.h>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace wayland
{

AWL_BACKENDS_WAYLAND_MAKE_REGISTRY_OBJECT(
	compositor
);

}
}
}

#endif

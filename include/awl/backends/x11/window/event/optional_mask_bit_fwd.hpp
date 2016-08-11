#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_OPTIONAL_MASK_BIT_FWD_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_OPTIONAL_MASK_BIT_FWD_HPP_INCLUDED

#include <awl/backends/x11/window/event/mask_bit.hpp>
#include <fcppt/optional/object_fwd.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{
namespace event
{

typedef
fcppt::optional::object<
	awl::backends::x11::window::event::mask_bit
>
optional_mask_bit;

}
}
}
}
}

#endif

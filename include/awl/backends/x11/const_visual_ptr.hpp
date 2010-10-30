#ifndef AWL_BACKENDS_X11_CONST_VISUAL_PTR_HPP_INCLUDED
#define AWL_BACKENDS_X11_CONST_VISUAL_PTR_HPP_INCLUDED

#include <awl/backends/x11/visual_fwd.hpp>
#include <fcppt/shared_ptr.hpp>

namespace awl
{
namespace backends
{
namespace x11
{
typedef
fcppt::shared_ptr
<
	visual const
>
const_visual_ptr;
}
}
}

#endif

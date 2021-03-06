#ifndef AWL_BACKENDS_X11_WINDOW_OBJECT_UNIQUE_PTR_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_OBJECT_UNIQUE_PTR_HPP_INCLUDED

#include <awl/backends/x11/window/object_fwd.hpp>
#include <fcppt/unique_ptr_impl.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{

typedef
fcppt::unique_ptr<
	awl::backends::x11::window::object
>
object_unique_ptr;

}
}
}
}

#endif

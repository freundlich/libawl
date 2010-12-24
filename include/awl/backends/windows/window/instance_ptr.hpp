#ifndef AWL_BACKENDS_WINDOWS_WINDOW_INSTANCE_PTR_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_INSTANCE_PTR_HPP_INCLUDED

#include <awl/backends/windows/window/instance_fwd.hpp>
#include <fcppt/shared_ptr.hpp>

namespace awl
{
namespace backends
{
namespace windows
{
namespace window
{

typedef fcppt::shared_ptr<
	window::instance
> instance_ptr;

}
}
}
}

#endif
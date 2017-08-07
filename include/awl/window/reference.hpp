#ifndef AWL_WINDOW_REFERENCE_HPP_INCLUDED
#define AWL_WINDOW_REFERENCE_HPP_INCLUDED

#include <awl/window/object_fwd.hpp>
#include <fcppt/reference_impl.hpp>


namespace awl
{
namespace window
{

typedef
fcppt::reference<
	awl::window::object
>
reference;

}
}

#endif

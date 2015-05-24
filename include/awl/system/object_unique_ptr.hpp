#ifndef AWL_SYSTEM_OBJECT_UNIQUE_PTR_HPP_INCLUDED
#define AWL_SYSTEM_OBJECT_UNIQUE_PTR_HPP_INCLUDED

#include <awl/system/object_fwd.hpp>
#include <fcppt/unique_ptr_impl.hpp>


namespace awl
{
namespace system
{

typedef
fcppt::unique_ptr<
	awl::system::object
>
object_unique_ptr;

}
}

#endif

#ifndef AWL_EVENT_BASE_UNIQUE_PTR_HPP_INCLUDED
#define AWL_EVENT_BASE_UNIQUE_PTR_HPP_INCLUDED

#include <awl/event/base_fwd.hpp>
#include <fcppt/unique_ptr_impl.hpp>


namespace awl
{
namespace event
{

typedef
fcppt::unique_ptr<
	awl::event::base
>
base_unique_ptr;

}
}

#endif

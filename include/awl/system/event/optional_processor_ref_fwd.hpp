#ifndef AWL_SYSTEM_EVENT_OPTIONAL_PROCESSOR_REF_FWD_HPP_INCLUDED
#define AWL_SYSTEM_EVENT_OPTIONAL_PROCESSOR_REF_FWD_HPP_INCLUDED

#include <awl/system/event/processor_fwd.hpp>
#include <fcppt/optional/reference_fwd.hpp>


namespace awl
{
namespace system
{
namespace event
{

typedef
fcppt::optional::reference<
	awl::system::event::processor
>
optional_processor_ref;

}
}
}

#endif

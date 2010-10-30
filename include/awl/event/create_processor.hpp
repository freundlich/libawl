#ifndef AWL_EVENT_CREATE_PROCESSOR_HPP_INCLUDED
#define AWL_EVENT_CREATE_PROCESSOR_HPP_INCLUDED

#include <awl/event/processor_ptr.hpp>
#include <awl/window/instance_ptr.hpp>
#include <awl/symbol.hpp>

namespace awl
{
namespace event
{

AWL_SYMBOL
event::processor_ptr const
create_processor(
	awl::window::instance_ptr
);

}
}

#endif

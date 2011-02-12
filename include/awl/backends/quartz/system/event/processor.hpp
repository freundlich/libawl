#ifndef AWL_BACKENDS_QUARTZ_SYSTEM_EVENT_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_QUARTZ_SYSTEM_EVENT_PROCESSOR_HPP_INCLUDED

#include <awl/backends/quartz/system/event/processor_fwd.hpp>
#include <awl/system/event/processor.hpp>
#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <fcppt/noncopyable.hpp>

namespace awl
{
namespace backends
{
namespace quartz
{
namespace system
{
namespace event
{

class AWL_CLASS_SYMBOL processor
:
	public awl::system::event::processor
{
	FCPPT_NONCOPYABLE(
		processor
	);
protected:
	AWL_SYMBOL
	processor();
public:
	AWL_SYMBOL
	~processor();
};

}
}
}
}
}

#endif
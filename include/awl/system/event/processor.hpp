#ifndef AWL_SYSTEM_EVENT_PROCESSOR_HPP_INCLUDED
#define AWL_SYSTEM_EVENT_PROCESSOR_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/main/exit_code_fwd.hpp>
#include <awl/main/optional_exit_code_fwd.hpp>
#include <awl/system/event/processor_fwd.hpp>
#include <awl/window/object_fwd.hpp>
#include <awl/window/event/processor_unique_ptr.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace system
{
namespace event
{

class AWL_CLASS_SYMBOL processor
{
	FCPPT_NONCOPYABLE(
		processor
	);
protected:
	AWL_DETAIL_SYMBOL
	processor();
public:
	virtual
	awl::main::optional_exit_code
	poll() = 0;

	virtual
	awl::main::optional_exit_code
	next() = 0;

	virtual
	awl::window::event::processor_unique_ptr
	create_window_processor(
		awl::window::object &
	) = 0;

	virtual
	void
	quit(
		awl::main::exit_code
	) = 0;

	AWL_DETAIL_SYMBOL
	virtual
	~processor() = 0;
};

}
}
}

#endif

#ifndef AWL_BACKENDS_X11_SYSTEM_EVENT_ORIGINAL_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_X11_SYSTEM_EVENT_ORIGINAL_PROCESSOR_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <awl/backends/x11/event/object_fwd.hpp>
#include <awl/backends/x11/system/event/callback.hpp>
#include <awl/backends/x11/system/event/map_key.hpp>
#include <awl/backends/x11/system/event/opcode.hpp>
#include <awl/backends/x11/system/event/processor.hpp>
#include <awl/backends/x11/system/event/type.hpp>
#include <awl/backends/x11/system/object_fwd.hpp>
#include <awl/main/exit_code.hpp>
#include <awl/system/optional_exit_code.hpp>
#include <awl/system/event/processor.hpp>
#include <awl/system/event/quit_callback.hpp>
#include <awl/system/event/quit_signal.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/object_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/ptr_container/ptr_map.hpp>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace system
{
namespace event
{

class AWL_CLASS_SYMBOL original_processor
:
	public awl::backends::x11::system::event::processor
{
	FCPPT_NONCOPYABLE(
		original_processor
	);
public:
	AWL_SYMBOL
	explicit
	original_processor(
		x11::system::object &
	);

	AWL_SYMBOL
	~original_processor();

	AWL_SYMBOL
	bool
	poll();

	AWL_SYMBOL
	void
	quit(
		awl::main::exit_code
	);

	AWL_SYMBOL
	bool
	running() const;

	AWL_SYMBOL
	awl::main::exit_code const
	exit_code() const;

	AWL_SYMBOL
	fcppt::signal::auto_connection
	quit_callback(
		awl::system::event::quit_callback const &
	);

	AWL_SYMBOL
	fcppt::signal::auto_connection
	register_callback(
		x11::system::event::opcode const &,
		x11::system::event::type const &,
		x11::system::event::callback const &
	);

	AWL_SYMBOL
	void
	process(
		x11::event::object const &
	);
private:
	awl::backends::x11::system::object &system_;

	typedef fcppt::signal::object<
		event::function
	> signal;

	typedef boost::ptr_map<
		event::map_key,
		signal
	> event_signal_map;

	event_signal_map signals_;

	awl::system::optional_exit_code exit_code_;

	awl::system::event::quit_signal quit_signal_;
};

}
}
}
}
}

#endif

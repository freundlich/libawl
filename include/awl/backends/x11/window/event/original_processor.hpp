#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_ORIGINAL_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_ORIGINAL_PROCESSOR_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/backends/x11/atom.hpp>
#include <awl/backends/x11/window/object_fwd.hpp>
#include <awl/backends/x11/window/event/callback.hpp>
#include <awl/backends/x11/window/event/function.hpp>
#include <awl/backends/x11/window/event/mask.hpp>
#include <awl/backends/x11/window/event/object_fwd.hpp>
#include <awl/backends/x11/window/event/processor.hpp>
#include <awl/backends/x11/window/event/type.hpp>
#include <awl/backends/x11/window/event/unregister_callback.hpp>
#include <awl/backends/x11/window/event/wm_protocols.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/window/event/close_callback.hpp>
#include <awl/window/event/close_signal.hpp>
#include <awl/window/event/destroy_callback.hpp>
#include <awl/window/event/destroy_signal.hpp>
#include <awl/window/event/hide_callback.hpp>
#include <awl/window/event/hide_signal.hpp>
#include <awl/window/event/processor.hpp>
#include <awl/window/event/resize_callback.hpp>
#include <awl/window/event/resize_signal.hpp>
#include <awl/window/event/show_callback.hpp>
#include <awl/window/event/show_signal.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/signal/auto_connection_container.hpp>
#include <fcppt/signal/auto_connection_fwd.hpp>
#include <fcppt/signal/object_decl.hpp>
#include <fcppt/signal/unregister/base_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <map>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{
namespace event
{

class AWL_CLASS_SYMBOL original_processor
:
	public awl::backends::x11::window::event::processor
{
	FCPPT_NONCOPYABLE(
		original_processor
	);
public:
	AWL_DETAIL_SYMBOL
	original_processor(
		awl::backends::x11::window::object &,
		awl::backends::x11::window::event::unregister_callback const &
	);

	AWL_DETAIL_SYMBOL
	~original_processor()
	override;

	AWL_DETAIL_SYMBOL
	fcppt::signal::auto_connection
	close_callback(
		awl::window::event::close_callback const &
	)
	override;

	AWL_DETAIL_SYMBOL
	fcppt::signal::auto_connection
	destroy_callback(
		awl::window::event::destroy_callback const &
	)
	override;

	AWL_DETAIL_SYMBOL
	fcppt::signal::auto_connection
	hide_callback(
		awl::window::event::hide_callback const &
	)
	override;

	AWL_DETAIL_SYMBOL
	fcppt::signal::auto_connection
	resize_callback(
		awl::window::event::resize_callback const &
	)
	override;

	AWL_DETAIL_SYMBOL
	fcppt::signal::auto_connection
	show_callback(
		awl::window::event::show_callback const &
	)
	override;

	AWL_DETAIL_SYMBOL
	awl::window::object &
	window() const
	override;

	AWL_DETAIL_SYMBOL
	awl::backends::x11::window::object &
	x11_window() const
	override;

	AWL_DETAIL_SYMBOL
	fcppt::signal::auto_connection
	register_callback(
		awl::backends::x11::window::event::type,
		awl::backends::x11::window::event::callback const &
	)
	override;

	void
	process(
		awl::backends::x11::window::event::object const &
	)
	override;
private:
	void
	unregister(
		awl::backends::x11::window::event::type
	);

	void
	on_client_message(
		awl::backends::x11::window::event::object const &
	);

	void
	on_configure(
		awl::backends::x11::window::event::object const &
	);

	void
	on_destroy(
		awl::backends::x11::window::event::object const &
	);

	void
	on_map(
		awl::backends::x11::window::event::object const &
	);

	void
	on_unmap(
		awl::backends::x11::window::event::object const &
	);

	awl::backends::x11::window::object &window_;

	awl::backends::x11::window::event::unregister_callback const unregister_;

	typedef
	fcppt::signal::object<
		awl::backends::x11::window::event::function,
		fcppt::signal::unregister::base
	>
	signal;

	typedef
	std::map<
		awl::backends::x11::window::event::type,
		signal
	>
	event_signal_map;

	typedef
	unsigned
	mask_count;

	typedef
	std::map<
		awl::backends::x11::window::event::mask,
		mask_count
	>
	mask_count_map;

	typedef
	std::map<
		awl::backends::x11::window::event::type,
		mask_count
	>
	type_count_map;

	event_signal_map signals_;

	mask_count_map mask_counts_;

	type_count_map type_counts_;

	awl::backends::x11::window::event::mask event_mask_;

	awl::backends::x11::atom const wm_protocols_atom_;

	awl::backends::x11::atom const wm_delete_window_atom_;

	awl::backends::x11::window::event::wm_protocols const wm_protocols_;

	awl::window::event::close_signal close_signal_;

	awl::window::event::destroy_signal destroy_signal_;

	awl::window::event::hide_signal hide_signal_;

	awl::window::event::resize_signal resize_signal_;

	awl::window::event::show_signal show_signal_;

	fcppt::signal::auto_connection_container const connections_;
};

}
}
}
}
}

#endif

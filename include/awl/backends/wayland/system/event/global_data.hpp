#ifndef AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_GLOBAL_DATA_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_GLOBAL_DATA_HPP_INCLUDED

#include <awl/backends/wayland/display_reference.hpp>
#include <awl/backends/wayland/optional_compositor.hpp>
#include <awl/backends/wayland/optional_shell.hpp>
#include <awl/backends/wayland/optional_shm.hpp>
#include <awl/backends/wayland/system/event/global_data_fwd.hpp>
#include <awl/backends/wayland/system/seat/set.hpp>
#include <awl/event/container.hpp>
#include <awl/main/optional_exit_code.hpp>
#include <fcppt/nonmovable.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/log/object_fwd.hpp>


namespace awl
{
namespace backends
{
namespace wayland
{
namespace system
{
namespace event
{

struct global_data
{
	FCPPT_NONMOVABLE(
		global_data
	);
public:
	global_data(
		fcppt::reference<
			fcppt::log::object
		>,
		awl::backends::wayland::display_reference
	);

	~global_data();

	fcppt::reference<
		fcppt::log::object
	> const log_; // NOLINT(misc-non-private-member-variables-in-classes)

	// NOLINTNEXTLINE(misc-non-private-member-variables-in-classes)
	awl::backends::wayland::display_reference const display_;

	// NOLINTNEXTLINE(misc-non-private-member-variables-in-classes)
	awl::backends::wayland::optional_compositor compositor_;

	// NOLINTNEXTLINE(misc-non-private-member-variables-in-classes)
	awl::backends::wayland::optional_shell shell_;

	// NOLINTNEXTLINE(misc-non-private-member-variables-in-classes)
	awl::backends::wayland::optional_shm shm_;

	// NOLINTNEXTLINE(misc-non-private-member-variables-in-classes)
	awl::backends::wayland::system::seat::set seats_;

	// NOLINTNEXTLINE(misc-non-private-member-variables-in-classes)
	awl::main::optional_exit_code exit_code_;

	// NOLINTNEXTLINE(misc-non-private-member-variables-in-classes)
	awl::event::container last_events_;
};

}
}
}
}
}

#endif

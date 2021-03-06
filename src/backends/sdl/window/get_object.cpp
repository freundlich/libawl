#include <awl/backends/sdl/window/get_data.hpp>
#include <awl/backends/sdl/window/get_object.hpp>
#include <awl/backends/sdl/window/native_reference.hpp>
#include <awl/backends/sdl/window/object_data_name.hpp>
#include <awl/backends/sdl/window/object_fwd.hpp>
#include <fcppt/assert/optional_error.hpp>
#include <fcppt/cast/from_void_ptr.hpp>


awl::backends::sdl::window::object &
awl::backends::sdl::window::get_object(
	awl::backends::sdl::window::native_reference const _window
)
{
	return
		*fcppt::cast::from_void_ptr<
			awl::backends::sdl::window::object *
		>(
			FCPPT_ASSERT_OPTIONAL_ERROR(
				awl::backends::sdl::window::get_data(
					_window,
					awl::backends::sdl::window::object_data_name()
				)
			)
		);
}

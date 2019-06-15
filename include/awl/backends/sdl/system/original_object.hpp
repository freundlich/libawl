#ifndef AWL_BACKENDS_SDL_SYSTEM_ORIGINAL_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_SDL_SYSTEM_ORIGINAL_OBJECT_HPP_INCLUDED

#include <awl/backends/sdl/system/init.hpp>
#include <awl/backends/sdl/system/object.hpp>
#include <awl/cursor/object_unique_ptr.hpp>
#include <awl/cursor/optional_type_fwd.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/system/object.hpp>
#include <awl/system/event/processor_fwd.hpp>
#include <awl/visual/object_unique_ptr.hpp>
#include <awl/window/object_unique_ptr.hpp>
#include <awl/window/parameters_fwd.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace sdl
{
namespace system
{

class AWL_DETAIL_CLASS_SYMBOL original_object
:
	public awl::backends::sdl::system::object
{
	FCPPT_NONCOPYABLE(
		original_object
	);
public:
	AWL_DETAIL_SYMBOL
	original_object();

	AWL_DETAIL_SYMBOL
	~original_object()
	override;

	AWL_DETAIL_SYMBOL
	awl::window::object_unique_ptr
	create_window(
		awl::window::parameters const &
	)
	override;

	AWL_DETAIL_SYMBOL
	awl::system::event::processor &
	processor()
	override;

	AWL_DETAIL_SYMBOL
	awl::visual::object_unique_ptr
	default_visual()
	override;

	AWL_DETAIL_SYMBOL
	awl::cursor::object_unique_ptr
	create_cursor(
		awl::cursor::optional_type const &
	)
	override;
private:
	awl::backends::sdl::system::init const init_;
};

}
}
}
}

#endif

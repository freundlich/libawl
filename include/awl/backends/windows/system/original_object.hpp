#ifndef AWL_BACKENDS_WINDOWS_SYSTEM_ORIGINAL_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_SYSTEM_ORIGINAL_OBJECT_HPP_INCLUDED

#include <awl/backends/windows/counted_wndclass.hpp>
#include <awl/backends/windows/system/object.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/system/event/processor_fwd.hpp>
#include <awl/system/event/processor_unique_ptr.hpp>
#include <awl/visual/object_unique_ptr.hpp>
#include <awl/window/object_unique_ptr.hpp>
#include <awl/window/optional_object_unique_ptr_fwd.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <unordered_map>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace system
{

class original_object
:
	public awl::backends::windows::system::object
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
	awl::window::optional_object_unique_ptr
	focus_window()
	override;
private:
	void
	unregister_wndclass(
		fcppt::string const &
	);

	typedef
	std::unordered_map<
		fcppt::string,
		awl::backends::windows::counted_wndclass
	>
	wndclass_map;

	wndclass_map wndclasses_;

	awl::system::event::processor_unique_ptr const processor_;
};

}
}
}
}

#endif

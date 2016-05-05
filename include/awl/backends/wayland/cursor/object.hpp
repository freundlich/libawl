#ifndef AWL_BACKENDS_WAYLAND_CURSOR_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_CURSOR_OBJECT_HPP_INCLUDED

#include <awl/backends/wayland/cursor/object_fwd.hpp>
#include <awl/backends/wayland/cursor/optional_fwd.hpp>
#include <awl/cursor/object.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace wayland
{
namespace cursor
{

class AWL_CLASS_SYMBOL object
:
	public awl::cursor::object
{
	FCPPT_NONCOPYABLE(
		object
	);
protected:
	AWL_DETAIL_SYMBOL
	object();
public:
	AWL_DETAIL_SYMBOL
	~object()
	override;

	virtual
	awl::backends::wayland::cursor::optional
	get() const = 0;
};

}
}
}
}

#endif

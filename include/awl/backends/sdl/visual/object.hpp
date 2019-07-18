#ifndef AWL_BACKENDS_SDL_VISUAL_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_SDL_VISUAL_OBJECT_HPP_INCLUDED

#include <awl/backends/sdl/visual/flags.hpp>
#include <awl/backends/sdl/visual/object_fwd.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/visual/object.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace sdl
{
namespace visual
{

class AWL_DETAIL_CLASS_SYMBOL object
:
	public awl::visual::object
{
	FCPPT_NONCOPYABLE(
		object
	);
public:
	AWL_DETAIL_SYMBOL
	explicit
	object(
		awl::backends::sdl::visual::flags
	);

	AWL_DETAIL_SYMBOL
	~object()
	override;

	AWL_DETAIL_SYMBOL
	awl::backends::sdl::visual::flags
	flags() const;

	AWL_DETAIL_SYMBOL
	virtual
	void
	apply() const;
private:
	awl::backends::sdl::visual::flags const flags_;
};

}
}
}
}

#endif

#include <awl/backends/sdl/exception.hpp>
#include <awl/backends/sdl/cursor/convert_predefined.hpp>
#include <awl/backends/sdl/cursor/object.hpp>
#include <awl/backends/sdl/cursor/predefined.hpp>
#include <awl/cursor/type.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <SDL_mouse.h>
#include <fcppt/config/external_end.hpp>


awl::backends::sdl::cursor::predefined::predefined(
	awl::cursor::type const _type
)
:
	awl::backends::sdl::cursor::object{},
	impl_{
		SDL_CreateSystemCursor(
			awl::backends::sdl::cursor::convert_predefined(
				_type
			)
		)
	}
{
	if(
		this->impl_
		==
		nullptr
	)
		throw
			awl::backends::sdl::exception{
				FCPPT_TEXT("CreateSystemCursor failed")
			};
}

awl::backends::sdl::cursor::predefined::~predefined()
{
	SDL_FreeCursor(
		this->impl_
	);
}

SDL_Cursor *
awl::backends::sdl::cursor::predefined::get() const
{
	return
		this->impl_;
}

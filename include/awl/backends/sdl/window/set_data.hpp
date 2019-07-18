#ifndef AWL_BACKENDS_SDL_WINDOW_SET_DATA_HPP_INCLUDED
#define AWL_BACKENDS_SDL_WINDOW_SET_DATA_HPP_INCLUDED

#include <awl/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <SDL_video.h>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace sdl
{
namespace window
{

AWL_DETAIL_SYMBOL
void
set_data(
	SDL_Window &,
	std::string const &,
	void *
);

}
}
}
}

#endif
#ifndef AWL_BACKENDS_WAYLAND_CURSOR_NAME_FWD_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_CURSOR_NAME_FWD_HPP_INCLUDED

#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace wayland
{
namespace cursor
{

FCPPT_MAKE_STRONG_TYPEDEF(
	std::string,
	name
);

}
}
}
}

#endif

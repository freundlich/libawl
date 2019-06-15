#ifndef AWL_CURSOR_OPTIONAL_TYPE_FWD_HPP_INCLUDED
#define AWL_CURSOR_OPTIONAL_TYPE_FWD_HPP_INCLUDED

#include <awl/cursor/type_fwd.hpp>
#include <fcppt/optional/object_fwd.hpp>


namespace awl
{
namespace cursor
{

typedef
fcppt::optional::object<
	awl::cursor::type
>
optional_type;

}
}

#endif

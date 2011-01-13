#ifndef AWL_MAINLOOP_NULLARY_CALLBACK_HPP_INCLUDED
#define AWL_MAINLOOP_NULLARY_CALLBACK_HPP_INCLUDED

#include <fcppt/function/object_fwd.hpp>

namespace awl
{
namespace mainloop
{

typedef fcppt::function::object<
	void ()
> nullary_callback;

}
}

#endif
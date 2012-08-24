#ifndef AWL_WINDOW_EVENT_HIDE_CALLBACK_FWD_HPP_INCLUDED
#define AWL_WINDOW_EVENT_HIDE_CALLBACK_FWD_HPP_INCLUDED

#include <awl/window/event/hide_function.hpp>
#include <fcppt/function/object_fwd.hpp>


namespace awl
{
namespace window
{
namespace event
{

typedef fcppt::function::object<
	awl::window::event::hide_function
> hide_callback;

}
}
}

#endif
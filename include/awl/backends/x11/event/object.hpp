#ifndef AWL_BACKENDS_X11_EVENT_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_X11_EVENT_OBJECT_HPP_INCLUDED

#include <awl/backends/x11/event/object_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace event
{

class object
{
public:
	AWL_DETAIL_SYMBOL
	explicit object(
		XEvent const &
	);

	AWL_DETAIL_SYMBOL
	XEvent const &
	get() const;

	AWL_DETAIL_SYMBOL
	XEvent &
	get();
private:
	XEvent event_;
};

}
}
}
}

#endif

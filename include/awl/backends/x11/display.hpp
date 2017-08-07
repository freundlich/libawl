#ifndef AWL_BACKENDS_X11_DISPLAY_HPP_INCLUDED
#define AWL_BACKENDS_X11_DISPLAY_HPP_INCLUDED

#include <awl/backends/x11/Xlib.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace x11
{

class AWL_DETAIL_CLASS_SYMBOL display
{
	FCPPT_NONCOPYABLE(
		display
	);
protected:
	AWL_DETAIL_SYMBOL
	display();
public:
	virtual
	Display *
	get() const = 0;

	AWL_DETAIL_SYMBOL
	virtual
	~display() = 0;
};

}
}
}

#endif

#ifndef AWL_BACKENDS_COCOA_WINDOW_INSTANCE_HPP_INCLUDED
#define AWL_BACKENDS_COCOA_WINDOW_INSTANCE_HPP_INCLUDED

#include <awl/window/instance.hpp>
#include <awl/symbol.hpp>
#include <awl/window/parameters_fwd.hpp>
#include <awl/window/bit_depth.hpp>
#include <awl/window/stencil_buffer.hpp>
#include <awl/window/depth_buffer.hpp>
#include <awl/backends/cocoa/window/event/processor_fwd.hpp>
#include <awl/backends/cocoa/event/processor_fwd.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/optional_impl.hpp>

@class NSWindow;

namespace awl
{
namespace backends
{
namespace cocoa
{
namespace window
{
class instance
:
	public awl::window::instance
{
FCPPT_NONCOPYABLE(
		instance);
public:
	AWL_SYMBOL
	explicit
	instance(
			awl::window::parameters const &);

	AWL_SYMBOL
	void
	show();

	AWL_SYMBOL
	awl::window::dim const
	size() const;

	AWL_SYMBOL
	bool
	has_opengl() const;

	AWL_SYMBOL
	fcppt::optional<awl::window::bit_depth::type> const
	bit_depth() const;

	AWL_SYMBOL
	fcppt::optional<awl::window::stencil_buffer::type> const
	stencil_buffer() const;

	AWL_SYMBOL
	fcppt::optional<awl::window::depth_buffer::type> const
	depth_buffer() const;

	AWL_SYMBOL
	NSWindow *
	window_handle();

	AWL_SYMBOL
	~instance();
private:
	friend class cocoa::window::event::processor;
	friend class cocoa::event::processor;

	__strong NSWindow *window_;
	bool has_opengl_;
	fcppt::optional<awl::window::bit_depth::type> bit_depth_;
	fcppt::optional<awl::window::stencil_buffer::type> stencil_buffer_;
	fcppt::optional<awl::window::depth_buffer::type> depth_buffer_;
};
}
}
}
}

#endif

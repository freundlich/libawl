#ifndef AWL_EVENT_CONCRETE_CONNECTION_HPP_INCLUDED
#define AWL_EVENT_CONCRETE_CONNECTION_HPP_INCLUDED

#include <awl/event/concrete_connection_fwd.hpp>
#include <awl/event/connection.hpp>
#include <awl/event/connection_function.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace event
{

class concrete_connection
:
	public awl::event::connection
{
	FCPPT_NONCOPYABLE(
		concrete_connection
	);
public:
	explicit
	concrete_connection(
		awl::event::connection_function &&
	);

	~concrete_connection()
	override;
private:
	awl::event::connection_function const function_;
};

}
}

#endif

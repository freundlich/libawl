#include <awl/backends/x11/signal/connection.hpp>

awl::backends::x11::signal::connection::connection(
	fcppt::signal::auto_connection _connection,
	signal::unregister_callback const &_callback
)
:
	connection_(
		move(
			_connection
		)
	),
	callback_(_callback)
{}

awl::backends::x11::signal::connection::~connection()
{
	callback_();
}
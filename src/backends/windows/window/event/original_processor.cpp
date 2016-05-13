#include <awl/exception.hpp>
#include <awl/backends/windows/default_wnd_proc.hpp>
#include <awl/backends/windows/lparam.hpp>
#include <awl/backends/windows/message.hpp>
#include <awl/backends/windows/message_type.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/wparam.hpp>
#include <awl/backends/windows/cursor/object.hpp>
#include <awl/backends/windows/window/object.hpp>
#include <awl/backends/windows/window/event/combine_result.hpp>
#include <awl/backends/windows/window/event/object.hpp>
#include <awl/backends/windows/window/event/original_processor.hpp>
#include <awl/backends/windows/window/event/processor.hpp>
#include <awl/backends/windows/window/event/return_type.hpp>
#include <awl/backends/windows/window/event/wnd_proc.hpp>
#include <awl/window/dim.hpp>
#include <awl/window/event/close.hpp>
#include <awl/window/event/close_callback.hpp>
#include <awl/window/event/close_signal.hpp>
#include <awl/window/event/destroy.hpp>
#include <awl/window/event/destroy_callback.hpp>
#include <awl/window/event/hide.hpp>
#include <awl/window/event/hide_callback.hpp>
#include <awl/window/event/resize.hpp>
#include <awl/window/event/resize_callback.hpp>
#include <awl/window/event/show.hpp>
#include <awl/window/event/show_callback.hpp>
#include <fcppt/identity.hpp>
#include <fcppt/make_int_range.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/strong_typedef_construct_cast.hpp>
#include <fcppt/text.hpp>
#include <fcppt/algorithm/map.hpp>
#include <fcppt/assign/make_container.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/cast/to_unsigned_fun.hpp>
#include <fcppt/container/find_opt_mapped.hpp>
#include <fcppt/container/maybe_back.hpp>
#include <fcppt/optional/bind.hpp>
#include <fcppt/optional/from.hpp>
#include <fcppt/optional/to_exception.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/auto_connection_container.hpp>
#include <fcppt/signal/object_impl.hpp>
#include <fcppt/type_iso/strong_typedef.hpp>
#include <fcppt/config/external_begin.hpp>
#include <functional>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4355)
awl::backends::windows::window::event::original_processor::original_processor(
	awl::backends::windows::window::object &_window
)
:
	awl::backends::windows::window::event::processor(),
	window_(
		_window
	),
	signals_(),
	user_messages_(
		// TODO: We need something better for this, like a sparse map
		fcppt::algorithm::map<
			user_message_vector
		>(
			fcppt::make_int_range(
				fcppt::strong_typedef_construct_cast<
					awl::backends::windows::message_type,
					fcppt::cast::to_unsigned_fun
				>(
					WM_USER
				),
				fcppt::strong_typedef_construct_cast<
					awl::backends::windows::message_type,
					fcppt::cast::to_unsigned_fun
				>(
					WM_USER
					+
					128
				)
			),
			fcppt::identity{}
		)
	),
	close_signal_(
		awl::window::event::close_signal::combiner_function{
			[](
				bool const _arg1,
				bool const _arg2
			)
			{
				return
					_arg1
					&&
					_arg2;
			}
		},
		awl::window::event::close_signal::initial_value{
			true
		}
	),
	destroy_signal_(),
	hide_signal_(),
	resize_signal_(),
	show_signal_(),
	connections_(
		fcppt::assign::make_container<
			fcppt::signal::auto_connection_container
		>(
			this->register_callback(
				fcppt::strong_typedef_construct_cast<
					awl::backends::windows::message_type,
					fcppt::cast::to_unsigned_fun
				>(
					WM_CLOSE
				),
				awl::backends::windows::window::event::callback{
					std::bind(
						&awl::backends::windows::window::event::original_processor::on_close,
						this,
						std::placeholders::_1
					)
				}
			),
			this->register_callback(
				fcppt::strong_typedef_construct_cast<
					awl::backends::windows::message_type,
					fcppt::cast::to_unsigned_fun
				>(
					WM_DESTROY
				),
				awl::backends::windows::window::event::callback{
					std::bind(
						&awl::backends::windows::window::event::original_processor::on_destroy,
						this,
						std::placeholders::_1
					)
				}
			),
			this->register_callback(
				fcppt::strong_typedef_construct_cast<
					awl::backends::windows::message_type,
					fcppt::cast::to_unsigned_fun
				>(
					WM_SIZE
				),
				awl::backends::windows::window::event::callback{
					std::bind(
						&awl::backends::windows::window::event::original_processor::on_resize,
						this,
						std::placeholders::_1
					)
				}
			),
			this->register_callback(
				fcppt::strong_typedef_construct_cast<
					awl::backends::windows::message_type,
					fcppt::cast::to_unsigned_fun
				>(
					WM_SHOWWINDOW
				),
				awl::backends::windows::window::event::callback{
					std::bind(
						&awl::backends::windows::window::event::original_processor::on_show,
						this,
						std::placeholders::_1
					)
				}
			),
			this->register_callback(
				fcppt::strong_typedef_construct_cast<
					awl::backends::windows::message_type,
					fcppt::cast::to_unsigned_fun
				>(
					WM_SETCURSOR
				),
				awl::backends::windows::window::event::callback{
					std::bind(
						&awl::backends::windows::window::event::original_processor::on_setcursor,
						this,
						std::placeholders::_1
					)
				}
			)
		)
	)
{
	::SetWindowLongPtr(
		window_.hwnd(),
		GWLP_USERDATA,
		reinterpret_cast<
			LONG_PTR
		>(
			this
		)
	);

	::SetWindowLongPtr(
		window_.hwnd(),
		GWLP_WNDPROC,
		reinterpret_cast<
			LONG_PTR
		>(
			awl::backends::windows::window::event::wnd_proc
		)
	);
}
FCPPT_PP_POP_WARNING

awl::backends::windows::window::event::original_processor::~original_processor()
{
	::SetWindowLongPtr(
		window_.hwnd(),
		GWLP_WNDPROC,
		reinterpret_cast<
			LONG_PTR
		>(
			awl::backends::windows::default_wnd_proc
		)
	);

	// FIXME: Where do we have to do this before we can destroy the cursor?
	if(
		window_.cursor().has_value()
	)
		::SetCursor(
			nullptr
		);
}

fcppt::signal::auto_connection
awl::backends::windows::window::event::original_processor::close_callback(
	awl::window::event::close_callback const &_callback
)
{
	return
		close_signal_.connect(
			_callback
		);
}

fcppt::signal::auto_connection
awl::backends::windows::window::event::original_processor::destroy_callback(
	awl::window::event::destroy_callback const &_callback
)
{
	return
		destroy_signal_.connect(
			_callback
		);
}

fcppt::signal::auto_connection
awl::backends::windows::window::event::original_processor::hide_callback(
	awl::window::event::hide_callback const &_callback
)
{
	return
		hide_signal_.connect(
			_callback
		);
}

fcppt::signal::auto_connection
awl::backends::windows::window::event::original_processor::resize_callback(
	awl::window::event::resize_callback const &_callback
)
{
	return
		resize_signal_.connect(
			_callback
		);
}

fcppt::signal::auto_connection
awl::backends::windows::window::event::original_processor::show_callback(
	awl::window::event::show_callback const &_callback
)
{
	return
		show_signal_.connect(
			_callback
		);
}

fcppt::signal::auto_connection
awl::backends::windows::window::event::original_processor::register_callback(
	awl::backends::windows::message_type const _type,
	awl::backends::windows::window::event::callback const &_func
)
{
	return
		fcppt::optional::from(
			fcppt::container::find_opt_mapped(
				signals_,
				_type
			),
			[
				this,
				_type
			]()
			{
				return
					fcppt::make_ref(
						signals_.insert(
							std::make_pair(
								_type,
								signal_type(
									signal_type::combiner_function{
										awl::backends::windows::window::event::combine_result
									},
									signal_type::initial_value{
										awl::backends::windows::window::event::return_type()
									}
								)
							)
						).first->second
					);
			}
		).get().connect(
			_func
		);
}

void
awl::backends::windows::window::event::original_processor::process(
	awl::backends::windows::message const &_message
)
{
	::TranslateMessage(
		&_message.get()
	);

	::DispatchMessage(
		&_message.get()
	);
}

awl::backends::windows::message_type
awl::backends::windows::window::event::original_processor::allocate_user_message()
{
	awl::backends::windows::message_type const result(
		fcppt::optional::to_exception(
			fcppt::container::maybe_back(
				user_messages_
			),
			[]{
				return
					awl::exception{
						FCPPT_TEXT("User messages exhausted.")
					};
			}
		).get()
	);

	// TODO: This is ugly
	user_messages_.pop_back();

	return
		result;
}

void
awl::backends::windows::window::event::original_processor::free_user_message(
	awl::backends::windows::message_type const _message
)
{
	user_messages_.push_back(
		_message
	);
}

awl::backends::windows::window::event::return_type
awl::backends::windows::window::event::original_processor::execute_callback(
	awl::backends::windows::message_type const _type,
	awl::backends::windows::wparam const _wparam,
	awl::backends::windows::lparam const _lparam
)
{
	return
		fcppt::optional::bind(
			fcppt::container::find_opt_mapped(
				signals_,
				_type
			),
			[
				_wparam,
				_lparam
			](
				fcppt::reference<
					signal_type
				> const _signal
			)
			{
				return
					_signal.get()(
						awl::backends::windows::window::event::object(
							_wparam,
							_lparam
						)
					);
			}
		);
}

awl::backends::windows::window::event::return_type
awl::backends::windows::window::event::original_processor::on_close(
	awl::backends::windows::window::event::object const &
)
{
	return
		close_signal_(
			awl::window::event::close()
		)
		?
			awl::backends::windows::window::event::return_type()
		:
			awl::backends::windows::window::event::return_type(
				0
			)
		;
}

awl::backends::windows::window::event::return_type
awl::backends::windows::window::event::original_processor::on_destroy(
	awl::backends::windows::window::event::object const &
)
{
	destroy_signal_(
		awl::window::event::destroy()
	);

	return
		awl::backends::windows::window::event::return_type();
}

awl::backends::windows::window::event::return_type
awl::backends::windows::window::event::original_processor::on_resize(
	awl::backends::windows::window::event::object const &_event
)
{
	resize_signal_(
		awl::window::event::resize(
			awl::window::dim(
				fcppt::cast::size<
					awl::window::dim::value_type
				>(
					LOWORD(
						_event.lparam().get()
					)
				),
				fcppt::cast::size<
					awl::window::dim::value_type
				>(
					HIWORD(
						_event.lparam().get()
					)
				)
			)
		)
	);

	return
		awl::backends::windows::window::event::return_type();
}

awl::backends::windows::window::event::return_type
awl::backends::windows::window::event::original_processor::on_show(
	awl::backends::windows::window::event::object const &_event
)
{
	switch(
		_event.wparam().get()
	)
	{
	case TRUE:
		show_signal_(
			awl::window::event::show()
		);
		break;
	case FALSE:
		hide_signal_(
			awl::window::event::hide()
		);
		break;
	}

	return
		awl::backends::windows::window::event::return_type();
}

awl::backends::windows::window::event::return_type
awl::backends::windows::window::event::original_processor::on_setcursor(
	awl::backends::windows::window::event::object const &_event
)
{
	return
		fcppt::optional::bind(
			window_.cursor(),
			[
				&_event
			](
				fcppt::reference<
					awl::backends::windows::cursor::object const
				> const _cursor
			)
			{
				if(
					LOWORD(
						_event.lparam().get()
					)
					==
					HTCLIENT
				)
				{
					::SetCursor(
						_cursor.get().get()
					);

					return
						awl::backends::windows::window::event::return_type(
							TRUE
						);
				}

				return
					awl::backends::windows::window::event::return_type();
			}
		);
}

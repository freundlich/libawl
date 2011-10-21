#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/window/event/original_processor.hpp>
#include <awl/backends/windows/window/event/return_type.hpp>
#include <awl/backends/windows/window/event/wnd_proc.hpp>
#include <fcppt/optional_impl.hpp>


LRESULT CALLBACK
awl::backends::windows::window::event::wnd_proc(
	HWND const _hwnd,
	UINT const _msg,
	WPARAM const _wparam,
	LPARAM const _lparam
)
{
	awl::backends::windows::window::event::original_processor *const processor(
		reinterpret_cast<
			awl::backends::windows::window::event::original_processor *
		>(
			::GetWindowLongPtr(
				_hwnd,
				GWLP_USERDATA
			)
		)
	);

	{
		awl::backends::windows::window::event::return_type const ret(
			processor->execute_callback(
				_msg,
				_wparam,
				_lparam
			)
		);

		if (ret)
			return *ret;
	}

	switch(
		_msg
	)
	{
	case WM_CLOSE:
		return 0;
	default:
		return
			::DefWindowProc(
				_hwnd,
				_msg,
				_wparam,
				_lparam
			);
	}
}

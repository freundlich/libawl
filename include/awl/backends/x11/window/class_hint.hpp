#ifndef AWL_BACKENDS_X11_WINDOW_CLASS_HINT_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_CLASS_HINT_HPP_INCLUDED

#include <awl/backends/x11/window/class_hint_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/strong_typedef.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{

class class_hint
{
public:
	FCPPT_MAKE_STRONG_TYPEDEF(
		std::string,
		res_name_type
	);

	FCPPT_MAKE_STRONG_TYPEDEF(
		std::string,
		res_class_type
	);

	AWL_DETAIL_SYMBOL
	class_hint(
		res_name_type &&,
		res_class_type &&
	);

	AWL_DETAIL_SYMBOL
	std::string const &
	res_name() const;

	AWL_DETAIL_SYMBOL
	std::string const &
	res_class() const;
private:
	res_name_type res_name_;

	res_class_type res_class_;
};

}
}
}
}

#endif

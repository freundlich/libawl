#ifndef AWL_BACKENDS_POSIX_PROCESSOR_BASE_HPP_INCLUDED
#define AWL_BACKENDS_POSIX_PROCESSOR_BASE_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/backends/posix/processor_base_fwd.hpp>
#include <awl/backends/posix/processor_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace posix
{

class AWL_CLASS_SYMBOL processor_base
{
	FCPPT_NONCOPYABLE(
		processor_base
	);
protected:
	AWL_DETAIL_SYMBOL
	processor_base();
public:
	AWL_DETAIL_SYMBOL
	virtual
	~processor_base() = 0;

	virtual
	awl::backends::posix::processor &
	fd_processor() = 0;
};

}
}
}

#endif
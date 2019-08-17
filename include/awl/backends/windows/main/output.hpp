#ifndef AWL_BACKENDS_WINDOWS_MAIN_OUTPUT_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_MAIN_OUTPUT_HPP_INCLUDED

#include <awl/detail/symbol.hpp>
#include <awl/main/output.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/filesystem/ofstream.hpp>
#include <fcppt/io/ostream_fwd.hpp>
#include <fcppt/io/scoped_rdbuf.hpp>
#include <fcppt/config/external_begin.hpp>
#include <filesystem>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace main
{

class output
:
	public awl::main::output
{
	FCPPT_NONCOPYABLE(
		output
	);
public:
	AWL_DETAIL_SYMBOL
	output(
		fcppt::io::ostream &,
		std::filesystem::path const &
	);

	AWL_DETAIL_SYMBOL
	~output()
	override;
private:
	fcppt::filesystem::ofstream stream_;

	fcppt::io::scoped_rdbuf const scoped_rdbuf_;
};

}
}
}
}

#endif

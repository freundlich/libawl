#ifndef AWL_DETAIL_EXPORT_CLASS_INSTANTIATION_HPP_INCLUDED
#define AWL_DETAIL_EXPORT_CLASS_INSTANTIATION_HPP_INCLUDED

#if defined(AWL_STATIC_LINK)
#	define AWL_DETAIL_EXPORT_CLASS_INSTANTIATION
#else
#	include <fcppt/symbol/export_class_instantiation.hpp>
#	define AWL_DETAIL_EXPORT_CLASS_INSTANTIATION FCPPT_SYMBOL_EXPORT_CLASS_INSTANTIATION
#endif

#endif

FIND_PATH(
	WINE_INCLUDE_DIR
	NAMES windows.h
	PATHS ${WINE_ROOT}/include
)

FIND_LIBRARY(
	WINE_LIBRARY
	NAMES wine
	PATHS ${WINE_ROOT}/lib ${WINE_ROOT}/libs/wine
)

IF(
	WINE_LIBRARY
)
	GET_FILENAME_COMPONENT(
		WINE_LIBRARY_DIR
		${WINE_LIBRARY}
		PATH
	)
ENDIF()

IF(
	NOT WINE_DLL_PATH
)
	SET(
		WINE_DLL_PATH
		${WINE_ROOT}/dlls
	)
ENDIF()

FOREACH(
	COMPONENT
	${Wine_FIND_COMPONENTS}
)
	FIND_FILE(
		WINE_${COMPONENT}_LIBRARY
		NAMES ${COMPONENT}.dll.so
		PATHS ${WINE_DLL_PATH}/${COMPONENT}
	)

	IF(
		NOT WINE_${COMPONENT}_LIBRARY
	)
		MESSAGE(
			FATAL_ERROR
			"${COMPONENT} not found!"
		)
	ENDIF()
ENDFOREACH()

INCLUDE(FindPackageHandleStandardArgs)

FIND_PACKAGE_HANDLE_STANDARD_ARGS(
	WINE
	DEFAULT_MSG
	WINE_INCLUDE_DIR
	WINE_LIBRARY
)

if(WIN32)
	set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
endif()

set(CURVE_SOURCES 
    "${CMAKE_CURRENT_LIST_DIR}/circle.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/ellipse.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/spiral.cpp"
	)

set(CURVE_HEADERS
    "${CMAKE_CURRENT_LIST_DIR}/circle.h"
    "${CMAKE_CURRENT_LIST_DIR}/ellipse.h"
	"${CMAKE_CURRENT_LIST_DIR}/spiral.h"
	"${CMAKE_CURRENT_LIST_DIR}/icurve.h"
	)
	
add_library(curves ${CURVE_SOURCES} ${CURVE_HEADERS})
install(TARGETS curves DESTINATION .)
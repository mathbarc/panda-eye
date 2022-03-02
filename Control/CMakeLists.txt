find_package(Qt5 COMPONENTS Core Widgets Gui REQUIRED) 
find_package(OpenCV COMPONENTS core REQUIRED)

set(CONTROL_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include CACHE PATH "View include dir")
include_directories(${VIEW_INCLUDE_DIR} ${CONTROL_INCLUDE_DIR})

file(GLOB CONTROL_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp)
file(GLOB CONTROL_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp)

qt5_wrap_cpp(CONTROL_WRAPPED_HEADERS ${CONTROL_HEADERS})

add_library(Control ${CONTROL_SOURCES} ${CONTROL_HEADERS} ${CONTROL_WRAPPED_HEADERS})
target_link_libraries(Control View Qt5::Core Qt5::Widgets Qt5::Gui ${OpenCV_LIBRARIES})
 
 

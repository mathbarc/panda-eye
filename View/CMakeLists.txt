find_package(Qt5 COMPONENTS Core Widgets Gui REQUIRED) 
find_package(OpenCV COMPONENTS core REQUIRED)

set(VIEW_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include CACHE PATH "View include dir")
include_directories(${VIEW_INCLUDE_DIR} ${CORE_INCLUDE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

file(GLOB VIEW_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp)
file(GLOB VIEW_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp)
file(GLOB VIEW_FORMS ${CMAKE_CURRENT_SOURCE_DIR}/forms/*.ui)


qt5_wrap_cpp(VIEW_WRAPPED_HEADERS ${VIEW_HEADERS})
qt5_wrap_ui(VIEW_WRAPPED_UI ${VIEW_FORMS})

add_library(View ${VIEW_SOURCES} ${VIEW_HEADERS} ${VIEW_WRAPPED_HEADERS} ${VIEW_WRAPPED_UI})
target_link_libraries(View Core Qt5::Core Qt5::Widgets Qt5::Gui ${OpenCV_LIBRARIES})


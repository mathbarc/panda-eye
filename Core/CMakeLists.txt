find_package(Qt5 COMPONENTS Core Widgets Gui REQUIRED)
find_package(OpenCV COMPONENTS core imgcodecs videoio REQUIRED)


set(CORE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include CACHE PATH "View include dir")
include_directories( ${OpenCV_INCLUDE_DIRS} ${CORE_INCLUDE_DIR})

file(GLOB CORE_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp)
file(GLOB CORE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp)

qt5_wrap_cpp(CORE_WRAPPED_HEADERS ${CORE_HEADERS})

add_library(Core ${CORE_SOURCES} ${CORE_HEADERS} ${CORE_WRAPPED_HEADERS})
target_link_libraries(Core Qt5::Core Qt5::Widgets Qt5::Gui${OpenCV_LIBRARIES})
 
 

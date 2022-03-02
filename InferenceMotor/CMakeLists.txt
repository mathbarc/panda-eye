find_package(Qt5 COMPONENTS Core Widgets Gui REQUIRED) 
find_package(OpenCV COMPONENTS core REQUIRED)

set(INF_MOTOR_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include CACHE PATH "View include dir")
include_directories(${OpenCV_INCLUDE_DIRS} ${INF_MOTOR_INCLUDE_DIR})

file(GLOB INF_MOTOR_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp)
file(GLOB INF_MOTOR_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp)

qt5_wrap_cpp(INF_MOTOR_WRAPPED_HEADERS ${INF_MOTOR_HEADERS})

add_library(InfMotor ${INF_MOTOR_SOURCES} ${INF_MOTOR_HEADERS} ${INF_MOTOR_WRAPPED_HEADERS})
target_link_libraries(InfMotor Qt5::Core Qt5::Widgets Qt5::Gui ${OpenCV_LIBRARIES}) 

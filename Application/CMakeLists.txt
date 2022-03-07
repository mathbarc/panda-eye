find_package(Qt5 COMPONENTS Core REQUIRED)

include_directories(${VIEW_INCLUDE_DIR} ${CONTROL_INCLUDE_DIR})

file(GLOB APP_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/source/app.cpp)

add_executable(${PROJECT_NAME} ${APP_SOURCES})
target_link_libraries(${PROJECT_NAME} Qt5::Core View Control) 

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        INCLUDES DESTINATION include)
 
 

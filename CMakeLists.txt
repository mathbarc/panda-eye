cmake_minimum_required(VERSION 3.12)

project("PandaEye" VERSION 0.1.0)


include(InstallRequiredSystemLibraries)

add_subdirectory(Core)
#add_subdirectory(ImgProcess)
#add_subdirectory(InferenceMotor)
add_subdirectory(View)
add_subdirectory(Control)
add_subdirectory(Application)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.md DESTINATION ".")
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/README.md DESTINATION ".")


set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Panda Eye")
set(CPACK_PACKAGE_VENDOR "Matheus Barcelos de Oliveira")
set(CPACK_RESOURCE_FILE_README ${CMAKE_CURRENT_SOURCE_DIR}/README.md)
set(CPACK_RESOURCE_FILE_LICENSE ${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.md)
set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Matheus Barcelos de Oliveira")
list(APPEND CPACK_DEBIAN_PACKAGE_DEPENDS libopencv-core-dev libopencv-highgui-dev libopencv-calib3d-dev libqt5gui5 libqt5core5a)
include(CPack)

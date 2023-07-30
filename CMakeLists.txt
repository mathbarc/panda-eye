cmake_minimum_required(VERSION 3.12)

project("PandaEye")

option(ENABLE_DCMTK "Add DCMTK to Read DICOM Image" OFF)
if (${ENABLE_DCMTK})
    add_compile_definitions(__DCMTK__)
endif ()

add_subdirectory(Core)
#add_subdirectory(ImgProcess)
#add_subdirectory(InferenceMotor)
add_subdirectory(View)
add_subdirectory(Control)
add_subdirectory(Application)


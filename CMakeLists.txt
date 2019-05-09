CMAKE_MINIMUM_REQUIRED(VERSION 3.0 )
PROJECT(LearnOpenCL)

set (CMAKE_CXX_STANDARD 14)

#SET (SHADER_PATH "${PROJECT_SOURCE_DIR}/shaders/")
#SET (TEXTURE_PATH "${PROJECT_SOURCE_DIR}/textures/")
#CONFIGURE_FILE ("${PROJECT_SOURCE_DIR}/include/LearnOpenGL/path_tool.h.in" "${PROJECT_SOURCE_DIR}/include/LearnOpenGL/path_tool.h")
if (WIN32)
    INCLUDE_DIRECTORIES ("C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v10.1/include")
    LINK_DIRECTORIES ("C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v10.1/lib/x64")
endif()

INCLUDE_DIRECTORIES ("${PROJECT_SOURCE_DIR}/include")

#Source Files and Headers
SET ( SRC_FILES "${PROJECT_SOURCE_DIR}/src/device_info.cpp" )
SET ( HEADER_FILES "${PROJECT_SOURCE_DIR}/include/LearnOpenCL/device_info.h"  )

#build library
ADD_LIBRARY (${PROJECT_NAME} ${SRC_FILES} ${HEADER_FILES})
TARGET_LINK_LIBRARIES (${PROJECT_NAME} OpenCL)

ADD_EXECUTABLE ( main "src/main.cpp" )
TARGET_LINK_LIBRARIES (main ${PROJECT_NAME})
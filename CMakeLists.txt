cmake_minimum_required(VERSION 3.16.3)

project(ort_infer)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/out)
# set(ONNXRUNTIME_DIR /home/chenliangjin/chenliangjin/Cpp_project/onnxruntime-linux-x64-gpu-1.12.0)
set(ONNXRUNTIME_DIR /home/liangjinchen/project/cpp_project/onnxruntime-linux-x64-gpu-1.12.0)

# find required opencv
find_package(OpenCV REQUIRED)

# If the package has been found, several variables will
# be set, you can find the full list with descriptions
# in the OpenCVConfig.cmake file.
# Print some message showing some of them
message(STATUS "OpenCV library status:")
message(STATUS "    config: ${OpenCV_DIR}")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")
message(STATUS "ONNXRUNTIME_DIR: ${ONNXRUNTIME_DIR}")

# directory of opencv headers
aux_source_directory(./src DIRSRCS)
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories("include/")
# add_subdirectory(include)

# name of executable file and path of source file
add_executable(ort_infer ${DIRSRCS})

target_include_directories(ort_infer PRIVATE "${ONNXRUNTIME_DIR}/include")

# link directory of opencv library
link_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(ort_infer ${OpenCV_LIBS} "${ONNXRUNTIME_DIR}/lib/libonnxruntime.so")
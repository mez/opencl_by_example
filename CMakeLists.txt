cmake_minimum_required(VERSION 3.0)
project(OpenCLByExamples)

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_SOURCE_DIR}/libs
        /opt/intel/opencl/include)
link_directories(/opt/intel/opencl/)
# If we are running on APPLE use framework to link.
# Else we assume you have opencl installed somewhere searchable.
IF(APPLE)
    link_libraries("-framework OpenCL")
else()
    link_libraries(OpenCL)
endif()

# every example gets their own executable.
add_executable(example0 example0.cc)

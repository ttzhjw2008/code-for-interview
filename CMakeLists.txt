cmake_minimum_required(VERSION 3.5.1)
project(sward_code)

add_definitions(-std=c++11 -fPIC)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -fPIC")
option(enable_unit_test "Build all tests." OFF)
set(CMAKE_BUILD_TYPE "debug")

if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/src")
    execute_process(
        COMMAND tar -xzvpf ${SRC_TAR} -C ${CMAKE_CURRENT_SOURCE_DIR}
    )
endif()

link_directories(
    ${CATKIN_DEVEL_PREFIX}/lib
)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

#message(STATUS "PROJECT_INCLUDE_DIR is: ${PROJECT_INCLUDE_DIR}, ${CMAKE_CURRENT_SOURCE_DIR}, ${PROJECT_SOURCE_DIR}")

#add_library(control_library SHARED VPS.cpp)

#add_dependencies(${PROJECT_NAME}
#    all_proto_library
#)

## test
if (${enable_unit_test})
    add_subdirectory(test)
endif()

#file(${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable(${PROJECT_NAME}  ${PROJECT_SOURCE_DIR}/src/main.cpp 
                ${PROJECT_SOURCE_DIR}/src/my_print.cpp
                ${PROJECT_SOURCE_DIR}/src/test.cpp)
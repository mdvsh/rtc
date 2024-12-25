cmake_minimum_required(VERSION 3.27)
project(rtc)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# Set enable output of compile commands during generation
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Build type - Release by default
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

add_executable(rtc src/main.cc
        src/vec3.h
        src/color.h
        src/color.cc
        src/ray.h
        src/utils.h
        src/utils.cc
        src/hittable.h
        src/sphere.h
        src/hittable_list.h
        src/hit_interval.h
        src/hit_interval.cc
        src/camera.h)

include_directories(src)

message (STATUS "Compiler ID: " ${CMAKE_CXX_COMPILER_ID})
message (STATUS "Release flags: " ${CMAKE_CXX_FLAGS_RELEASE})
message (STATUS "Debug flags: " ${CMAKE_CXX_FLAGS_DEBUG})

set(CMAKE_CXX_CLANG_TIDY
    clang-tidy;
    -header-filter=.*;
    -format-style=file)

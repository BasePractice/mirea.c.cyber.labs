cmake_minimum_required(VERSION 3.2.1)
project(mirea_c_cyber_labs)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(TASKS "01;02")

if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    set(CMAKE_C_LINK_FLAGS "${CMAKE_CXX_LINK_FLAGS} /SUBSYSTEM:CONSOLE /IGNORE:4099")
    set(CMAKE_CFLAGS "${CMAKE_CFLAGS} /arch:SSE2")
    if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
        set(CMAKE_CFLAGS "${CMAKE_CFLAGS} /MDd /bigobj")
        add_compile_options(/MDd /bigobj)
    else ()
        add_definitions(/MT)
        add_compile_options(/bigobj)
    endif ()
    add_definitions(/wd4267)
    add_definitions(/wd4250)
    add_definitions(/wd4996)
    add_definitions(/wd4334)
elseif (CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CFLAGS "${CMAKE_CFLAGS} -pedantic -Wp,-w -msse -msse2 -msse3 -fPIC -Wunused-result ")
else ()
    set(CMAKE_CFLAGS "${CMAKE_CFLAGS} -std=c90 -pedantic -Wp,-w -fPIC ")
    set(CMAKE_LINK_LIBRARY_FLAG "${CMAKE_LINK_LIBRARY_FLAG} -fPIC ")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fPIC ")
    set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -fPIC ")
endif ()

enable_testing()
include_directories(00)

add_subdirectory(01)

add_library(tests_main STATIC 00/catch2/catch.hpp 00/tests_main.cpp)


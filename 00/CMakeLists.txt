cmake_minimum_required(VERSION 3.2.1)
project(00.Base)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(.)

set(BASE_HEADER_FILES base_macro.h)
set(BASE_SOURCE_FILES base_math.c)
set(DEPENDENCY_LIBRARIES)

if (UNIX)
	list(APPEND DEPENDENCY_LIBRARIES m dl pthread rt)
endif ()

add_library(${PROJECT_NAME}_Library STATIC ${BASE_SOURCE_FILES} ${BASE_HEADER_FILES})
target_compile_definitions(${PROJECT_NAME}_Library PUBLIC BASE_MACRO)
target_link_libraries(${PROJECT_NAME}_Library PUBLIC ${DEPENDENCY_LIBRARIES})
add_library(Base::Math ALIAS ${PROJECT_NAME}_Library)

add_library(${PROJECT_NAME}_TestMain STATIC tests_main.c)
add_library(Test::Main ALIAS ${PROJECT_NAME}_TestMain)
target_link_libraries(${PROJECT_NAME}_TestMain PUBLIC ${CHECK_LIBRARIES})

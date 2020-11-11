cmake_minimum_required(VERSION 3.2.1)
project(01.Task)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(.)

set(BASE_HEADER_FILES base.h)
set(BASE_SOURCE_FILES )
set(MAIN_SOURCE_FILES main.c)
set(BASE_TEST_SOURCE_FILES)
set(TESTS_LIBRARIES)

foreach(TASK ${TASKS})
	add_library(${PROJECT_NAME}_${TASK}_Library STATIC ${TASK}.c ${BASE_SOURCE_FILES} ${BASE_HEADER_FILES} task_test.cpp)
	target_compile_definitions(${PROJECT_NAME}_${TASK}_Library PRIVATE TASK=${TASK})
	list(APPEND TESTS_LIBRARIES ${PROJECT_NAME}_${TASK}_Library)

	add_executable(${PROJECT_NAME}_${TASK} ${BASE_SOURCE_FILES} ${MAIN_SOURCE_FILES} ${BASE_HEADER_FILES})
	target_compile_definitions(${PROJECT_NAME}_${TASK} PRIVATE TASK=${TASK})
	target_link_libraries(${PROJECT_NAME}_${TASK} tests_main ${PROJECT_NAME}_${TASK}_Library)
endforeach()
add_executable(${PROJECT_NAME}_Tests ${TESTS_SOURCE_FILES} ${BASE_TEST_SOURCE_FILES} ${BASE_HEADER_FILES})

target_link_libraries(${PROJECT_NAME}_Tests tests_main ${TESTS_LIBRARIES})


cmake_minimum_required(VERSION 3.2.1)
project(01.Task)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(.)

set(BASE_HEADER_FILES base.h)
set(BASE_SOURCE_FILES )
set(MAIN_SOURCE_FILES main.c)
set(BASE_TEST_SOURCE_FILES)
set(TESTS_LIBRARIES)
set(DEPENDENCY_LIBRARIES)

if (CMAKE_COMPILER_IS_GNUCXX)
	list(APPEND DEPENDENCY_LIBRARIES m)
endif ()

foreach(TASK ${TASKS})
	add_library(${PROJECT_NAME}_${TASK}_Library STATIC ${TASK}.c ${BASE_SOURCE_FILES} ${BASE_HEADER_FILES})
	target_compile_definitions(${PROJECT_NAME}_${TASK}_Library PRIVATE TASK=${TASK})
	target_link_libraries(${PROJECT_NAME}_${TASK}_Library PUBLIC ${DEPENDENCY_LIBRARIES})
	list(APPEND TESTS_LIBRARIES ${PROJECT_NAME}_${TASK}_Library)

	add_executable(${PROJECT_NAME}_${TASK} ${BASE_SOURCE_FILES} ${MAIN_SOURCE_FILES} ${BASE_HEADER_FILES})
	target_compile_definitions(${PROJECT_NAME}_${TASK} PRIVATE TASK=${TASK})
	target_link_libraries(${PROJECT_NAME}_${TASK} ${PROJECT_NAME}_${TASK}_Library)
endforeach()

add_executable(${PROJECT_NAME}_Tests ${CMAKE_CURRENT_BINARY_DIR}/generated_tests.cpp ${BASE_TEST_SOURCE_FILES} ${BASE_HEADER_FILES})
target_link_libraries(${PROJECT_NAME}_Tests tests_main ${TESTS_LIBRARIES})

add_custom_command(
		OUTPUT
		${CMAKE_CURRENT_BINARY_DIR}/generated_tests.cpp
		PRE_BUILD
		COMMAND perl ${CMAKE_CURRENT_SOURCE_DIR}/generate_tests.pl > ${CMAKE_CURRENT_BINARY_DIR}/generated_tests.cpp
)
add_custom_target(${PROJECT_NAME}_Tests_Generated DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/generated_tests.cpp)
add_dependencies(${PROJECT_NAME}_Tests ${PROJECT_NAME}_Tests_Generated)
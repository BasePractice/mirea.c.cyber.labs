cmake_minimum_required(VERSION 3.2.1)
project(02.Task)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(.)

set(BASE_HEADER_FILES base.h)
set(BASE_SOURCE_FILES base.c)
set(MAIN_SOURCE_FILES main.c)
set(BASE_TEST_SOURCE_FILES)
set(TESTS_LIBRARIES)


foreach(TASK ${TASKS})
	add_library(${PROJECT_NAME}_${TASK}_Library STATIC ${TASK}.c ${BASE_SOURCE_FILES} ${BASE_HEADER_FILES})
	target_compile_definitions(${PROJECT_NAME}_${TASK}_Library PRIVATE TASK=${TASK})
	target_link_libraries(${PROJECT_NAME}_${TASK}_Library PUBLIC ${DEPENDENCY_LIBRARIES} Base::Math)
	list(APPEND TESTS_LIBRARIES ${PROJECT_NAME}_${TASK}_Library)

	add_executable(${PROJECT_NAME}_${TASK} ${BASE_SOURCE_FILES} ${MAIN_SOURCE_FILES} ${BASE_HEADER_FILES})
	target_compile_definitions(${PROJECT_NAME}_${TASK} PRIVATE TASK=${TASK})
	target_link_libraries(${PROJECT_NAME}_${TASK} ${PROJECT_NAME}_${TASK}_Library)

	add_test(${PROJECT_NAME}_Test${TASK} ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_${TASK})
	set_tests_properties(${PROJECT_NAME}_Test${TASK} PROPERTIES
			FAIL_REGULAR_EXPRESSION "FAILED"
			PASS_REGULAR_EXPRESSION "PASSED"
			)
endforeach()

add_executable(${PROJECT_NAME}_Tests ${CMAKE_CURRENT_BINARY_DIR}/generated_tests.c ${BASE_TEST_SOURCE_FILES} ${BASE_HEADER_FILES})
add_executable(${PROJECT_NAME}_BaseTests base_tests.c ${BASE_TEST_SOURCE_FILES} ${BASE_HEADER_FILES})
target_link_libraries(${PROJECT_NAME}_Tests Test::Main ${TESTS_LIBRARIES})
target_link_libraries(${PROJECT_NAME}_BaseTests Test::Main ${TESTS_LIBRARIES})

add_custom_command(
		OUTPUT
		${CMAKE_CURRENT_BINARY_DIR}/generated_tests.c
		PRE_BUILD
		COMMAND ${PERL_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/generate_tests.pl > ${CMAKE_CURRENT_BINARY_DIR}/generated_tests.c
)
add_custom_target(${PROJECT_NAME}_Tests_Generated DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/generated_tests.c)
add_dependencies(${PROJECT_NAME}_Tests ${PROJECT_NAME}_Tests_Generated)

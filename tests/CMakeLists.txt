project(${CMAKE_PROJECT_NAME}_tests)

# Clone Google Test
set(GOOGLETEST_DIR ${CMAKE_SOURCE_DIR}/tests/lib/googletest)

add_subdirectory(lib/googletest)
add_subdirectory(unit_tests)
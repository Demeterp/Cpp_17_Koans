include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(RUN_ALL_TESTS
        test_urok1.cpp
        test_sample1.cc
        test_urok0.cpp)

target_link_libraries(RUN_ALL_TESTS gtest gtest_main)
target_link_libraries(RUN_ALL_TESTS ${CMAKE_PROJECT_NAME}_lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(RUN_ALL_TESTS
        test_urok1.cpp
        test_sample1.cc
        test_strings.cpp test_data_types.cpp test_pointers.cpp test_string_stream.cpp test_valarray.cpp test_codeforce_defines.cpp test_vasya_good_sequence.cpp test_maximum_subarray.cpp test_bitset.cpp test_lower_bound.cpp)

target_link_libraries(RUN_ALL_TESTS gtest gtest_main)
target_link_libraries(RUN_ALL_TESTS ${CMAKE_PROJECT_NAME}_lib)
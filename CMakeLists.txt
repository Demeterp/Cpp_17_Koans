cmake_minimum_required(VERSION 3.9)
project(Cpp_17_Koans)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES 510_main.cpp c1_day0_main.cpp 510_2_main.cpp main.cpp edu50_a.cpp edu50_e.cpp techno2019_f.cpp r197_d_main.cpp r216_e_main.cpp r223_c_main.cpp r271_F.cpp r292_e.cpp)
add_executable(${CMAKE_PROJECT_NAME}_run ${SOURCE_FILES})

include_directories(src)

add_subdirectory(src)
add_subdirectory(tests)

target_link_libraries(${CMAKE_PROJECT_NAME}_run ${CMAKE_PROJECT_NAME}_lib)


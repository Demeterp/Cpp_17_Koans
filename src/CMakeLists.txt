project(${CMAKE_PROJECT_NAME}_lib)

set(HEADER_FILES sample1.h uchim_string.h )
set(SOURCE_FILES sample1.cc uchim_string.cpp)

add_library(${CMAKE_PROJECT_NAME}_lib STATIC  ${SOURCE_FILES}  ${HEADER_FILES})

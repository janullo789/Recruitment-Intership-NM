cmake_minimum_required(VERSION 3.0)

project(tests VERSION 0.0.1 LANGUAGES CXX)

set(INCLUDES ${CMAKE_SOURCE_DIR}/../include)
include_directories(${INCLUDES})

add_executable(${PROJECT_NAME} test.cpp)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

set(DOCTEST_DIR ${CMAKE_SOURCE_DIR}/../include)
target_include_directories(${PROJECT_NAME} PRIVATE ${DOCTEST_DIR})
target_sources(${PROJECT_NAME} PRIVATE ${DOCTEST_DIR}/doctest.h)
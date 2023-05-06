cmake_minimum_required(VERSION 3.21)
project(Task3 LANGUAGES CXX)

set(INCLUDES ${PROJECT_SOURCE_DIR}/include)
include_directories(${INCLUDES})

file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/source/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES} main.cpp)

target_compile_features(Task3 PUBLIC cxx_std_17)

install(TARGETS Task3)
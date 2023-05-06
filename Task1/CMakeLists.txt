cmake_minimum_required(VERSION 3.21)
project(Task1 LANGUAGES CXX)

set(INCLUDES ${PROJECT_SOURCE_DIR}/include)
include_directories(${INCLUDES})

file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/source/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES} main.cpp)
target_link_libraries(Task1 PRIVATE
    ${PROJECT_SOURCE_DIR}/library/sfml-graphics.lib
    ${PROJECT_SOURCE_DIR}/library/sfml-window.lib
    ${PROJECT_SOURCE_DIR}/library/sfml-system.lib
)
target_compile_features(Task1 PUBLIC cxx_std_17)

install(TARGETS Task1)
cmake_minimum_required(VERSION 3.27)
project(DetailFactory)

add_definitions(-DSOME_IMPORTANT_DEFINITION)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")

include_directories(
        ${PROJECT_SOURCE_DIR}
        ${PROJECT_SOURCE_DIR}/inc
        ${PROJECT_SOURCE_DIR}/src
)
file(GLOB_RECURSE SRC_FILES
        ${PROJECT_SOURCE_DIR}/src/*.cpp
)

if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    option(SERIALIZATION_TESTS "build tests (or on)" ON)
    if(SERIALIZATION_TESTS)
        add_library(tests ${SRC_FILES}
                src/details.cpp
                inc/details.h
                src/factory.cpp
                inc/factory.h
                src/machines.cpp
                inc/machines.h
                inc/employees.h
                src/employees.cpp)
        enable_testing()
        add_subdirectory(test)
    endif()
endif()

add_executable(${PROJECT_NAME}
        ${SRC_FILES}
        ${RELATED_FILES}
)
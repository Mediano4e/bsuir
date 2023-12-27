cmake_minimum_required(VERSION 3.14)
project(FACTORY_TEST)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(NO_DEV ON)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        Factory_Test
        detail_test.cpp
        machine_test.cpp
        employee_test.cpp
        factory_test.cpp
        ../src/details.cpp
        ../src/machines.cpp
        ../src/employees.cpp
        ../src/factory.cpp
)
target_link_libraries(
        Factory_Test
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(Factory_Test)
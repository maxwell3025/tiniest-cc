cmake_minimum_required(VERSION 3.31.4)

project(cpp_coroutines_test C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

## Setup Targets
### test_cc
set(test_cc_SOURCES
    test_cc.cpp
)

set(test_cc_HEADERS
)

add_executable(test_cc ${test_cc_SOURCES} ${test_cc_HEADERS})

target_link_libraries(test_cc PUBLIC
    gtest_main
    cc
)

### test_maxwell3025_fileio
set(test_maxwell3025_fileio_SOURCES
    test_maxwell3025_fileio.cpp
)

set(test_maxwell3025_fileio_HEADERS
    ../src/common/load_file.h
)

add_executable(test_maxwell3025_fileio ${test_maxwell3025_fileio_SOURCES} ${test_maxwell3025_fileio_HEADERS})

target_link_libraries(test_maxwell3025_fileio PUBLIC
    gtest_main
    maxwell3025_fileio
)

## Setup GoogleTest
include(GoogleTest)
gtest_discover_tests(test_cc)
gtest_discover_tests(test_maxwell3025_fileio)


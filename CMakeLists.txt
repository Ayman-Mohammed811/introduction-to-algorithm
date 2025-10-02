

# cmake_minimum_required(VERSION 3.16)

# project(introduction_to_algorithm LANGUAGES CXX)

# set(CMAKE_CXX_STANDARD 26)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add_executable(introduction_to_algorithm
#     src/main.cpp
# )

# cmake_minimum_required(VERSION 3.16)

# project(introduction_to_algorithm LANGUAGES CXX)

# set(CMAKE_CXX_STANDARD 26)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# include_directories(${CMAKE_SOURCE_DIR}/include)
# include_directories(${CMAKE_SOURCE_DIR}/include/datastructure)
# include_directories(${CMAKE_SOURCE_DIR}/include/sorting)

# file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)

# add_executable(introduction_to_algorithm ${SOURCES})


#cmake_minimum_required(VERSION 3.10)
#project(MyTest)
#
#enable_testing()
#find_package(GTest REQUIRED)
#
#add_executable(test
#    test/test.cpp)
#target_link_libraries(test GTest::gtest_main)
#
#include(GoogleTest)
#gtest_discover_tests(test)

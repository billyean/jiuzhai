cmake_minimum_required(VERSION 3.20)
project(jiuzhai)

set(CMAKE_CXX_STANDARD 17)

add_executable(jiuzhai main.cpp tests/test_ok.cpp)


include(CTest)
if(BUILD_TESTING)
    add_subdirectory(tests)

endif()
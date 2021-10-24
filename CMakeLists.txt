cmake_minimum_required(VERSION 3.16.3)
set (VCPKG_HOME "$ENV{HOME}/vcpkg") #IMPORTANT: change this to where your vcpkg exists.
set (CMAKE_TOOLCHAIN_FILE "${VCPKG_HOME}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_BUILD_TYPE Debug)

project(jiuzhai)

find_package(gRPC CONFIG REQUIRED)
find_package(faiss CONFIG REQUIRED)
find_package(glog CONFIG REQUIRED)
find_package(unixodbc CONFIG REQUIRED)
find_package(Protobuf CONFIG REQUIRED)
find_package(Threads REQUIRED)
find_package(BLAS REQUIRED )

add_subdirectory(external)
add_subdirectory(src)

include(CTest)
if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
# CMakeLists.txt
cmake_minimum_required(VERSION 3.16.3)

file(GLOB SRCS *.cpp *.h)

add_executable(jiuzhai ${SRCS})
target_link_libraries(jiuzhai
        Threads::Threads
        gRPC::grpc++
        p3protolib)

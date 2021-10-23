set(JIUZHAI_TEST_SRC
        test_ok.cpp
        )

add_executable(jiuzhai_test ${JIUZHAI_TEST_SRC})

include(FetchContent)
FetchContent_Declare(googletest
        URL "https://github.com/google/googletest/archive/release-1.10.0.tar.gz")
set(BUILD_GMOCK CACHE BOOL OFF)

target_link_libraries(jiuzhai_test PRIVATE
    gtest_main
        )
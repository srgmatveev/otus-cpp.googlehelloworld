

add_executable(Unit_Tests_run
        test_example.cpp
        )

set_target_properties(Unit_Tests_run  PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        COMPILE_OPTIONS -Wpedantic -Wall -Wextra
        )


if (NOT $ENV{TRAVIS_BUILD_NUMBER})

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

target_link_libraries(Unit_Tests_run gtest gtest_main)

else()

    find_package(GTest REQUIRED)
    find_package(Threads REQUIRED)
    include_directories(${GTEST_INCLUDE_DIRS})
    target_link_libraries(Unit_Tests_run ${GTEST_BOTH_LIBRARIES})
    target_link_libraries(Unit_Tests_run ${CMAKE_THREAD_LIBS_INIT})
endif()

target_link_libraries(Unit_Tests_run ${version_lib})
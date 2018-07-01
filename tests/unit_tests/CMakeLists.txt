find_package(Threads REQUIRED)

add_executable(Unit_Tests_run
        test_example.cpp
        )

set_target_properties(Unit_Tests_run  PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        COMPILE_OPTIONS -Wpedantic -Wall -Wextra
        )



include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

target_link_libraries(Unit_Tests_run gtest gtest_main)
target_link_libraries(Unit_Tests_run ${CMAKE_THREAD_LIBS_INIT})


target_link_libraries(Unit_Tests_run ${version_lib})
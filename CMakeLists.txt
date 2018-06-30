cmake_minimum_required(VERSION 3.9)

if($ENV{TRAVIS_BUILD_NUMBER})
    project(Google_hello_world_project VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else()
    project(Google_hello_world_project VERSION 0.0.1)
endif()

set(SRC_DIR "./src")
configure_file("${SRC_DIR}/version.h.in" "${SRC_DIR}/version.h")

set(SOURCE_FILES main.cpp)
add_executable(${CMAKE_PROJECT_NAME}_run ${SOURCE_FILES})

set_target_properties(${CMAKE_PROJECT_NAME}_run  PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        COMPILE_OPTIONS -Wpedantic -Wall -Wextra
       )



include_directories(src)

set(version_lib version_lib)

add_subdirectory(src)
add_subdirectory(tests)



target_link_libraries(${CMAKE_PROJECT_NAME}_run ${version_lib})

install(TARGETS ${CMAKE_PROJECT_NAME}_run RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT srgmatveev@gmail.com)

include (CPack)

enable_testing()

add_test(test_valid_version ./tests/unit_tests/Unit_Tests_run)


# Doxygen Build
option(BUILD_DOC "Build Documentation" ON)

find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(BUILD_DOC_DIR ${CMAKE_SOURCE_DIR}/build/docs)
    if(NOT EXISTS ${BUILD_DOC_DIR})
        file(MAKE_DIRECTORY ${BUILD_DOC_DIR})
    endif()

    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

    message("Doxygen buld started")
    add_custom_target(Doxygen ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
else(DOXYGEN_FOUND)
    message("Doxygen needs to be installed to generate the documentation.")
endif(DOXYGEN_FOUND)
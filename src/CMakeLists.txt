

set(VERSION_HEADER_FILES version_lib.h)
set(VERSION_SOURCE_FILES  "version_lib.cpp")


    add_library(${version_lib} STATIC
        ${VERSION_SOURCE_FILES} ${VERSION_HEADER_FILES}
         )

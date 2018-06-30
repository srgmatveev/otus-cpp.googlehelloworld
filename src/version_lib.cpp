//
// Created by sergio on 30.06.18.
//
#include "version_lib.h"

//#define MY_LOCAL 1

#ifndef MY_LOCAL
#include "version.h"
#endif


int get_version() {

#ifdef MY_LOCAL
    return 15;
#else
    return PROJECT_VERSION_PATCH;
#endif
}

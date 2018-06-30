#include "version_lib.h"
#include "gtest/gtest.h"

TEST(HelloWorldTest, VersionGreaterThenZero) {

    EXPECT_GT(get_version(),0);

}



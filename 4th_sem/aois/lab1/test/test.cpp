#include <gtest/gtest.h>
#include "../src/DirectForm.h"

TEST(TEST, Basic) {
    DirectForm t1(1), t2(2);
    t1.toString();
    EXPECT_FALSE(t1 == t2);
}
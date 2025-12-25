#include <gtest/gtest.h>
#include "D:\OS_labs\Lab_5\common\protocol.h"

TEST(Protocol, EnumValues) {
    ASSERT_EQ((int)CommandType::READ,1);
    ASSERT_EQ((int)CommandType::WRITE,2);
}

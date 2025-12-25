#include <gtest/gtest.h>
#include "D:\OS_labs\Lab_5\common\employee.h"
#include <cstring>

TEST(EmployeeValidation, NameLength) {
    Employee e{1,"123456789",10};
    ASSERT_LE(strlen(e.name),9);
}

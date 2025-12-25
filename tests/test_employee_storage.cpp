#include <gtest/gtest.h>
#include "D:\OS_labs\Lab_5\server\employee_storage.h"

TEST(EmployeeStorage, FindSuccess) {
    Employee e[2] = {{1,"A",10},{2,"B",20}};
    EmployeeStorage s(e,2);
    Employee out{};
    ASSERT_TRUE(s.Find(1,out));
    ASSERT_EQ(out.hours,10);
}

TEST(EmployeeStorage, FindFail) {
    Employee e[1] = {{1,"A",10}};
    EmployeeStorage s(e,1);
    Employee out{};
    ASSERT_FALSE(s.Find(99,out));
}

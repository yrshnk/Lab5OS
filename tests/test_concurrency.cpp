#include <gtest/gtest.h>
#include "D:\OS_labs\Lab_5\server\employee_storage.h"

TEST(Concurrency, Update) {
    Employee e[1] = {{1,"A",10}};
    EmployeeStorage s(e,1);
    Employee upd = {1,"A",50};
    ASSERT_TRUE(s.Update(upd));
    ASSERT_EQ(e[0].hours,50);
}

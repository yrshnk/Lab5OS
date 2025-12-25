#pragma once
#include "D:\OS_labs\Lab_5\common\employee.h"

class EmployeeStorage {
public:
    EmployeeStorage(Employee* data, int size);
    bool Find(int num, Employee& out) const;
    bool Update(const Employee& emp);
    int Size() const;
private:
    Employee* employees;
    int count;
};

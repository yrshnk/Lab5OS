#include "employee_storage.h"

EmployeeStorage::EmployeeStorage(Employee* data, int size)
    : employees(data), count(size) {}

bool EmployeeStorage::Find(int num, Employee& out) const {
    for (int i = 0; i < count; ++i) {
        if (employees[i].num == num) {
            out = employees[i];
            return true;
        }
    }
    return false;
}

bool EmployeeStorage::Update(const Employee& emp) {
    for (int i = 0; i < count; ++i) {
        if (employees[i].num == emp.num) {
            employees[i] = emp;
            return true;
        }
    }
    return false;
}

int EmployeeStorage::Size() const {
    return count;
}

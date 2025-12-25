#pragma once
#include <windows.h>
#include "D:\OS_labs\Lab_5\common\employee.h"
#include "D:\OS_labs\Lab_5\common\protocol.h"

class PipeClient {
public:
    PipeClient();
    ~PipeClient();
    bool ReadEmployee(int num, Employee& emp);
    bool WriteEmployee(const Employee& emp);
private:
    HANDLE pipe;
};

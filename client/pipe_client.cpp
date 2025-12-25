#include "pipe_client.h"

PipeClient::PipeClient() {
    pipe = CreateFileA(
        "\\.\pipe\server_pipe",
        GENERIC_READ | GENERIC_WRITE,
        0, NULL, OPEN_EXISTING, 0, NULL
    );
}

PipeClient::~PipeClient() {
    CloseHandle(pipe);
}

bool PipeClient::ReadEmployee(int num, Employee& emp) {
    CommandPacket packet{ CommandType::READ, num };
    DWORD bytes;
    WriteFile(pipe, &packet, sizeof(packet), &bytes, NULL);

    bool found;
    ReadFile(pipe, &found, sizeof(found), &bytes, NULL);
    if (!found) return false;

    ReadFile(pipe, &emp, sizeof(emp), &bytes, NULL);
    return true;
}

bool PipeClient::WriteEmployee(const Employee& emp) {
    CommandPacket packet{ CommandType::WRITE, emp.num };
    DWORD bytes;

    WriteFile(pipe, &packet, sizeof(packet), &bytes, NULL);
    bool found;
    ReadFile(pipe, &found, sizeof(found), &bytes, NULL);
    if (!found) return false;

    Employee oldEmp;
    ReadFile(pipe, &oldEmp, sizeof(oldEmp), &bytes, NULL);
    WriteFile(pipe, &emp, sizeof(emp), &bytes, NULL);
    return true;
}

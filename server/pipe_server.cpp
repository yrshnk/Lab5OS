#include "pipe_server.h"
#include "D:\OS_labs\Lab_5\common\protocol.h"
#include "D:\OS_labs\Lab_5\common\employee.h"
#include "employee_storage.h"
#include <iostream>

extern HANDLE gSemaphore;
extern HANDLE gMutex;
extern EmployeeStorage* gStorage;
extern int gReaderCount;

DWORD WINAPI ClientThread(LPVOID param) {
    HANDLE pipe = (HANDLE)param;
    DWORD readBytes, writeBytes;

    while (true) {
        CommandPacket packet{};
        if (!ReadFile(pipe, &packet, sizeof(packet), &readBytes, NULL) || readBytes == 0) {
            std::cout << "Клиент отключился.\n";
            break;
        }

        if (packet.command == CommandType::READ) {
            WaitForSingleObject(gMutex, INFINITE);
            gReaderCount++;
            if (gReaderCount == 1)
                WaitForSingleObject(gSemaphore, INFINITE);
            ReleaseMutex(gMutex);

            Employee emp{};
            bool found = gStorage->Find(packet.employeeNumber, emp);
            WriteFile(pipe, &found, sizeof(found), &writeBytes, NULL);
            if (found)
                WriteFile(pipe, &emp, sizeof(emp), &writeBytes, NULL);

            WaitForSingleObject(gMutex, INFINITE);
            gReaderCount--;
            if (gReaderCount == 0)
                ReleaseSemaphore(gSemaphore, 1, NULL);
            ReleaseMutex(gMutex);
        }
        else if (packet.command == CommandType::WRITE) {
            WaitForSingleObject(gSemaphore, INFINITE);

            Employee emp{};
            bool found = gStorage->Find(packet.employeeNumber, emp);
            WriteFile(pipe, &found, sizeof(found), &writeBytes, NULL);

            if (found) {
                WriteFile(pipe, &emp, sizeof(emp), &writeBytes, NULL);
                ReadFile(pipe, &emp, sizeof(emp), &readBytes, NULL);
                gStorage->Update(emp);
            }
            ReleaseSemaphore(gSemaphore, 1, NULL);
        }
        else if (packet.command == CommandType::EXIT) {
            break;
        }
    }

    DisconnectNamedPipe(pipe);
    CloseHandle(pipe);
    return 0;
}

#include <windows.h>
#include <iostream>
#include "pipe_server.h"
#include "employee_storage.h"

HANDLE gSemaphore;
HANDLE gMutex;
EmployeeStorage* gStorage;
int gReaderCount = 0;

int main() {
    int empCount, clientCount;
    std::cout << "Введите количество сотрудников: ";
    std::cin >> empCount;

    Employee* employees = new Employee[empCount];
    for (int i = 0; i < empCount; ++i) {
        std::cout << "Сотрудник " << i + 1 << ": ";
        std::cin >> employees[i].num >> employees[i].name >> employees[i].hours;
    }

    gStorage = new EmployeeStorage(employees, empCount);

    std::cout << "Введите количество клиентов: ";
    std::cin >> clientCount;

    gSemaphore = CreateSemaphore(NULL, 1, clientCount, L"WriteSemaphore");
    gMutex = CreateMutex(NULL, FALSE, L"SyncMutex");

    HANDLE* threads = new HANDLE[clientCount];

    for (int i = 0; i < clientCount; ++i) {
        HANDLE pipe = CreateNamedPipe(
            L"\\.\pipe\server_pipe",
            PIPE_ACCESS_DUPLEX,
            PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
            clientCount, 0, 0, INFINITE, NULL
        );

        std::cout << "Ожидание клиента...\n";
        ConnectNamedPipe(pipe, NULL);
        threads[i] = CreateThread(NULL, 0, ClientThread, pipe, 0, NULL);
    }

    WaitForMultipleObjects(clientCount, threads, TRUE, INFINITE);
    return 0;
}

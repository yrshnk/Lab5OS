#include "pipe_client.h"
#include <iostream>

int main() {
    PipeClient client;
    while (true) {
        std::cout << "Команда (read/write/exit): ";
        std::string cmd;
        std::cin >> cmd;

        if (cmd == "exit") break;

        int num;
        std::cout << "Номер сотрудника: ";
        std::cin >> num;

        if (cmd == "read") {
            Employee emp{};
            if (client.ReadEmployee(num, emp)) {
                std::cout << "Получено: " << emp.num << " "
                          << emp.name << " " << emp.hours << "\n";
            } else {
                std::cout << "Сотрудник не найден.\n";
            }
        }

        if (cmd == "write") {
            Employee emp{};
            std::cout << "Введите данные: ";
            std::cin >> emp.num >> emp.name >> emp.hours;
            if (client.WriteEmployee(emp))
                std::cout << "Обновление выполнено.\n";
            else
                std::cout << "Ошибка обновления.\n";
        }
    }
    return 0;
}

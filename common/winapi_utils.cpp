#include "winapi_utils.h"
#include <iostream>

void FatalWinError(const std::string& message) {
    std::cerr << "КРИТИЧЕСКАЯ ОШИБКА: " << message
              << ". Код WinAPI: " << GetLastError() << std::endl;
    ExitProcess(EXIT_FAILURE);
}

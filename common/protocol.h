#pragma once
enum class CommandType : int {
    READ  = 1,
    WRITE = 2,
    EXIT  = 3
};

struct CommandPacket {
    CommandType command;
    int employeeNumber;
};

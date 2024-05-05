#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>
#include <TlHelp32.h>
#include <string>


class TaskMan {
public:
    struct ProcessData {
        std::string Name;
        DWORD ProcessID;
    };




    std::vector<ProcessData> GetAllProcessesOnSystem();
};

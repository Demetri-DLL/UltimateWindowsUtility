#pragma once
#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <Psapi.h>

class ResMon
{
public:
    UINT64 GetTheImages(DWORD Pid);
    UINT64 GetTheMapped(DWORD Pid);
    void GetTheInfo(PROCESSENTRY32 Process);
    bool EnumProcesses();
    int Run();

};


#pragma once
#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <Psapi.h>
#include <unordered_map>

class ResMon
{
public:
    UINT64 GetTheImages(DWORD Pid);
    UINT64 GetTheMapped(DWORD Pid);
    void GetTheInfo(PROCESSENTRY32 Process);
    std::vector<float> convertToFloatVector(const std::vector<UINT64>& uint64Vector);
    bool EnumProcesses();
    int Run();
    std::unordered_map<std::wstring, UINT64> processMap;
    std::vector<std::wstring> ProcNames;
    std::vector<UINT64> ProcUsage;
};


#pragma once
#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <Psapi.h>
#include <unordered_map>
#include <string>
#include <locale>
#include <codecvt>

class ResMon
{//could use private functions and variables instead of making everything public
public:
    UINT64 GetTheImages(DWORD Pid);
    UINT64 GetTheMapped(DWORD Pid);
    void GetTheInfo(PROCESSENTRY32 Process);
    void WstringVecToString(std::vector<std::wstring>ProcNames);
    void StorageInfo();
    bool EnumProcesses();
    int Run();
    std::unordered_map<std::wstring, UINT64> processMap;
    std::vector<std::wstring> ProcNames;
    std::vector<UINT64> ProcUsage;
    std::vector<std::string> StringBuff;
    std::vector<char*> CharBuff;
    ULARGE_INTEGER FreeBytes;
    void MapToVec(std::unordered_map<std::wstring, UINT64>& Map);
    DISK_SPACE_INFORMATION DiskInfo;
};


#pragma once
#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <Psapi.h>
#include <unordered_map>
#include <string>
#include <locale>
#include <codecvt>
#include <algorithm>

class ResMon
{//could use private functions and variables instead of making everything public
public:
    UINT64 GetTheImages(DWORD Pid);
    UINT64 GetTheMapped(DWORD Pid);
    void GetTheInfo(PROCESSENTRY32 Process);
    void WstringVecToString(std::vector<std::wstring>ProcNames);
    void StorageInfo();
    UINT64 StorageConvert(ULARGE_INTEGER Pass);
    bool EnumProcesses();
    int Run();
    std::unordered_map<std::wstring, UINT64> processMap;
    std::vector<std::wstring> ProcNames;
    std::vector<UINT64> ProcUsage;
    std::vector<std::string> StringBuff;
    std::vector<char*> CharBuff;
    std::vector<UINT64> TotalStorage;
    std::vector<std::pair<std::wstring, UINT64>> VecPair;
    void MapToVec(std::unordered_map<std::wstring, UINT64>& Map);
    void ResMon::MapToVecPair(std::unordered_map<std::wstring, UINT64>& Map);
    bool comparePairs(const std::pair<std::wstring, UINT64>& a, const std::pair<std::wstring, UINT64>& b);
    ULARGE_INTEGER FreeBytes;
    UINT64 TotalFreeBytes;
    UINT64 TotalTotalBytes;
    ULARGE_INTEGER TotalBytes;
    DISK_SPACE_INFORMATION DiskInfo;
    LPCSTR Dir = ":\\";
    DWORD number = 100;
    char DriveBuff[100];
    char* SingleDrive;
};


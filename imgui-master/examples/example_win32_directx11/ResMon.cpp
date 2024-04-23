#include "ResMon.h"

/*
UINT64 ResMon::GetTheImages(DWORD Pid) {

    auto Snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, Pid);

    MODULEENTRY32 Entry;
    Entry.dwSize = sizeof(Entry);

    UINT64 TotalSize = 0;

    if (Module32First(Snapshot, &Entry)) {
        do {

            printf("Module: %ws fills 0x%llX\n", Entry.szModule, Entry.modBaseSize);

            TotalSize += Entry.modBaseSize;

        } while (Module32Next(Snapshot, &Entry));
    }

    CloseHandle(Snapshot);

    return TotalSize;
}
*/


void ResMon::convertWStringToCharPtr(_In_ std::wstring input, _Out_ char* outputString)
{
    size_t outputSize = input.length() + 1; // +1 for null terminator
    outputString = new char[outputSize];
    size_t charsConverted = 0;
    const wchar_t* inputW = input.c_str();
    wcstombs_s(&charsConverted, outputString, outputSize, inputW, input.length());
    // stack overflow code. https://stackoverflow.com/questions/18645874/converting-stdwsting-to-char-with-wcstombs-s
}

UINT64 ResMon::GetTheMapped(DWORD Pid) {

    auto Process = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, Pid);

    if (!Process)
        return 0;

    PROCESS_MEMORY_COUNTERS MemoryInfo;
    MemoryInfo.cb = sizeof(MemoryInfo);

    if (!GetProcessMemoryInfo(Process, &MemoryInfo, MemoryInfo.cb))
        return false;

    return MemoryInfo.PagefileUsage;
}

/* Actual memory usage calculator bla bla bla */
void ResMon::GetTheInfo(PROCESSENTRY32 Process) {
    
    auto Pid = Process.th32ProcessID;
    
    printf("Process: %ws \n", Process.szExeFile);
    /*
    auto ImageSizes = GetTheImages(Pid);

    printf("Size of all loaded images: 0x%llX \n", ImageSizes);
    */
    auto MappedBytes = GetTheMapped(Pid);

    printf("MappedBytes: 0x%llX \n", MappedBytes);
    auto Total = MappedBytes;
    std::wstring ProcNameConvert(Process.szExeFile); //convert the WCHAR to a string so it can be used in the map
    char buff[20];
    convertWStringToCharPtr(ProcNameConvert, buff);

    //processMap[ProcName] += Total; //add the keys that have the same process name. [] operator with maps can be dangerous.
    ProcUsage.push_back(Total);
    ProcNames.push_back(buff);//vectors are easier to use with the IMplot library

    printf("Total Memory Usage: 0x%llX \n", Total);
    printf("\n");
}
bool ResMon::EnumProcesses() {
    auto Snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
    if (!Snapshot)
        return false;
    PROCESSENTRY32 Entry;
    Entry.dwSize = sizeof(Entry);
    if (Process32First(Snapshot, &Entry)) {
        do {
                (void)GetTheInfo(Entry);
        } while (Process32Next(Snapshot, &Entry));
    }
    CloseHandle(Snapshot);
    return true;
}
int ResMon::Run() {
    (void)EnumProcesses();
    return 0;
}

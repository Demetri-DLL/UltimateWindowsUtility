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


void ResMon::WstringVecToString(std::vector<std::wstring>ProcNames) {


    for (int i = 0; i < ProcNames.size(); i++) {//this can be simplified so that there is only 1 buffer and 1 loop. The wstring can be converted to a string and then a char and then put into the vector.
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;

    StringBuff.push_back( converter.to_bytes(ProcNames[i]));
    }

    for (int i = 0; i < StringBuff.size(); i++) {
        char* cstr = StringBuff[i].data();
        CharBuff.push_back(cstr);
    }

}
//https://stackoverflow.com/questions/4804298/how-to-convert-wstring-into-string above code was inspired from this threads information As well as this https://stackoverflow.com/questions/7352099/stdstring-to-char
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

    if (std::wstring(Process.szExeFile).compare(L"System")&& std::wstring(Process.szExeFile).compare(L"Registry")) {//remove some problemetic processes from the loop
        //processMap[ProcName] += Total; //add the keys that have the same process name. [] operator with maps can be dangerous.
        ProcUsage.push_back(Total);
        ProcNames.push_back(ProcNameConvert);//vectors are easier to use with the IMplot library
    }

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
    WstringVecToString(ProcNames);
    CloseHandle(Snapshot);
    return true;
}
int ResMon::Run() {
    processMap.clear();
    ProcNames.clear();
    ProcUsage.clear();
    StringBuff.clear();
    CharBuff.clear();
    (void)EnumProcesses();
    return 0;
}

void ResMon::StorageInfo() {
    GetDiskFreeSpaceExA(NULL, NULL, NULL, FreeBytes);

}

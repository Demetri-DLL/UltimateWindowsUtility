#include "TaskMan.h"



std::vector<TaskMan::ProcessData> TaskMan::GetAllProcessesOnSystem() {

    auto Snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

    if (!Snapshot)
        return {};

    PROCESSENTRY32 Entry;
    Entry.dwSize = sizeof(Entry);

    std::vector<ProcessData> Buffer = {};

    if (Process32First(Snapshot, &Entry)) {
        do {

            ProcessData Temp;

            std::wstring ws = std::wstring(Entry.szExeFile);
            std::string s(ws.begin(), ws.end());

            Temp.Name = s;
            Temp.ProcessID = Entry.th32ProcessID;

            Buffer.push_back(Temp);

        } while (Process32Next(Snapshot, &Entry));
    }

    return Buffer;
}

#pragma once
#include "fileman.h"
#include "shlobj_core.h"


void FileMan::GetWindowsTempFold() {
    m_dwRetVal = GetTempPath(MAX_PATH, lpTempPathBuffer);


}

void FileMan::GetOSTempFold(){
   // GetWindowsDirectoryW(infoBuf, 32767); old legacy windows code
    SHGetKnownFolderPath(FOLDERID_Windows, 0, NULL, &OSTempPath);
    //Fixed to use newer windows function. was using legacy windows function that use bad datatypes.
    std::wstringstream ConcatVar;
    ConcatVar << OSTempPath << L"\\Temp";
    CoTaskMemFree(static_cast<void*>(OSTempPath));
    int i;
}

#pragma once
#include "fileman.h"


void FileMan::GetWindowsTempFold() {
    m_dwRetVal = GetTempPath(MAX_PATH,          // length of the buffer
        lpTempPathBuffer);

}

void FileMan::GetOSTempFold(){
    GetWindowsDirectory(infoBuf, 32767);
}

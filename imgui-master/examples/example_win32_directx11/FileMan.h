#pragma once



class FileMan
{
    TCHAR lpTempPathBuffer[MAX_PATH];
    DWORD dwRetVal = 0;


    FileMan();
    ~FileMan();

    void GetWindowsTempFold();



};


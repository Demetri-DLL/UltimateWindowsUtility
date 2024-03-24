#pragma once
#include "windows.h"
#include "iostream"



class FileMan
{
private:
    TCHAR lpTempPathBuffer[MAX_PATH];
    DWORD m_dwRetVal = 0;
    //TCHAR infoBuf[32767] = { '\0' };
    PWSTR OSTempPath = NULL;
    std::string ConcatVar = "\\Temp";

public:
  //  FileMan();
   // ~FileMan();

   
    void GetWindowsTempFold();
    void GetOSTempFold();





};


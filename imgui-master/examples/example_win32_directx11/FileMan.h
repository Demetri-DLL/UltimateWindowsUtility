#pragma once
#include "windows.h"
#include "iostream"



class FileMan
{
private:
    TCHAR lpTempPathBuffer[MAX_PATH];
    DWORD m_dwRetVal = 0;
    static TCHAR szPath[MAX_PATH];
    TCHAR infoBuf[32767] = { '\0' };
    const CHAR *tempfold = "\\Temp";

public:
  //  FileMan();
   // ~FileMan();

   
    void GetWindowsTempFold();
    void GetOSTempFold();





};


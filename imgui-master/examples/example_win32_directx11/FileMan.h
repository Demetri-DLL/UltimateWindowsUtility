#pragma once
#include "windows.h"
#include <iostream>
#include <sstream>
//#include <string>



class FileMan
{
private:
    TCHAR lpTempPathBuffer[MAX_PATH];
    DWORD m_dwRetVal = 0;
    //TCHAR infoBuf[32767] = { '\0' };
    wchar_t * OSTempPath = 0;
 

public:
  //  FileMan();
   // ~FileMan();

   
    void GetWindowsTempFold();
    void GetOSTempFold();





};


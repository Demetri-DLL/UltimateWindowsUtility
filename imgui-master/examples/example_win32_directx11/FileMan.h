#pragma once
#include "windows.h"
#include <iostream>
#include <sstream>
#include <filesystem>



class FileMan
{
private:
    wchar_t lpTempPathBuffer[MAX_PATH]; //or use TCHAR
    DWORD m_dwRetVal = 0;
    wchar_t* OSTempPath = 0;
    wchar_t* tempAdd = L"\\temp\\";
    wchar_t* chromePath = L"\\Google\\Chrome\\User Data";
    wchar_t* chromePathTemp = 0;

    std::error_code errorCode;

public:

    void deleteDir(const std::filesystem::path& dir);
    void GetWindowsTempFold();
    void GetOSTempFold();
    void GetChromeTemp();
};


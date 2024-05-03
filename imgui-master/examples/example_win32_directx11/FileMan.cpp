#pragma once
#include "fileman.h"
#include "shlobj_core.h"
#include <wchar.h>

void FileMan::deleteDir(const std::filesystem::path& dir) {
    for (const auto& entry : std::filesystem::directory_iterator(dir)) // stack overflow https://stackoverflow.com/questions/59077670/c-delete-all-files-and-subfolders-but-keep-the-directory-itself
        std::filesystem::remove_all(entry.path(),errorCode);
    //filesystem is a c++ 17 feature

}

void FileMan::GetWindowsTempFold() {
    GetTempPath(MAX_PATH, lpTempPathBuffer);

    std::filesystem::path tempFolderPath(lpTempPathBuffer);
    //deleteDir(lpTempPathBuffer);

}

void FileMan::GetOSTempFold(){/*
   // GetWindowsDirectoryW(infoBuf, 32767); old legacy windows code
    SHGetKnownFolderPath(FOLDERID_Windows, 0, NULL, &OSTempPath);
    //Fixed to use newer windows function. was using legacy windows function that use bad datatypes.
    wcsncat(OSTempPath, tempAdd, 6); //or 5?

    std::filesystem::path osTempFolderPath(OSTempPath);
    //deleteDir(OSTempPath);
    CoTaskMemFree(static_cast<void*>(OSTempPath));
    */



    wchar_t* OSTempPath = nullptr;
    HRESULT hr = SHGetKnownFolderPath(FOLDERID_Windows, 0, NULL, &OSTempPath);
    if (SUCCEEDED(hr)) {

        size_t bufferSize = wcslen(OSTempPath) + wcslen(tempAdd) + 1; // +1 for the null-terminator
        wchar_t* concatenatedPath = new wchar_t[bufferSize];

        wcscpy_s(concatenatedPath, bufferSize, OSTempPath);
        wcsncat(concatenatedPath, tempAdd, bufferSize - wcslen(concatenatedPath) - 1); // Ensure buffer size is sufficient


        delete[] concatenatedPath;
        CoTaskMemFree(static_cast<void*>(OSTempPath));
    }



}

void FileMan::GetChromeTemp() {
    SHGetKnownFolderPath(FOLDERID_LocalAppData, 0, NULL, &chromePathTemp);
    wcsncat(chromePathTemp, chromePath,30);
    //deleteDir(chromePathTemp);
}

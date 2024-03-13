#include "Framework.h"


void FileMan::GetWindowsTempFold() {
    dwRetVal = GetTempPath(MAX_PATH,          // length of the buffer
        lpTempPathBuffer);

}

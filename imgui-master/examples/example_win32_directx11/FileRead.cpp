#include "FileRead.h"

void FileRead::WriteFileData(std::time_t Output,const char* FileName) {
    std::ofstream file(FileName);

    if (file.is_open()) {
        file << std::ctime(&Output);
        file.close();
        std::cout << "String written to file successfully." << std::endl;
    }
    else {
        std::cout << "File Not Found." << std::endl;
    }
}

std::string FileRead::ReadFileData(int No){
    std::string err = "Never";

    if (No == 1) {
        std::ifstream in("output1.txt");
        if (in.is_open()) {
            std::string Buff;

            std::getline(in,Buff);

            in.close();
            return Buff;
        }else {
            std::cout << "File Error" << std::endl;
        }
    }

    if (No == 2) {
        std::ifstream in("output2.txt");
        if (in.is_open()) {
            std::string Buff;

            std::getline(in, Buff);

            in.close();
            return Buff;
        }else {
            std::cout << "File Error" << std::endl;
        }
    }
    if (No == 3) {
        std::ifstream in("output3.txt");
        if (in.is_open()) {
            std::string Buff;

            std::getline(in, Buff);

            in.close();
            return Buff;
        }else {
            std::cout << "File Error" << std::endl;
        }
    }



    return err;
}

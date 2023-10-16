#pragma once
#include <cstdint>
#include <string>
#include <fstream>

class DataWrite {

public:

    DataWrite( std::string& path, uint32_t Num );
    void readFile(); // читаем файл



private:
    uint32_t N;
    std::string path;


    // создаем пакеты данных
    // пишем их в новый файл
};



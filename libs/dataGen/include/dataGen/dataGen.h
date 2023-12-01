#pragma once

#include <cstdint>
#include <string>
#include <fstream>


class DataGenerator {
public:

    void readConfig( const std::string& filename ); // чтение файла конфигурации
    void writeToFile( const std::string& path ); // запись строк в файл

    uint16_t getN() {
        return N;
    }
    char getSym() {
        return this->sym;
    }
    uint32_t getK() {
        return this->k;
    }
    uint16_t getMaxLen() {
        return N * rmax_len;
    }

private:

    uint16_t N = 50; // максимальная длина пакета в байтах, задается в config
    char sym = '*'; // символ для заполнения строк
    uint32_t k = 100; // количество строк
    uint16_t rmax_len =  1;// коэффициент для установки максимальной длины строки
    void getSett( std::ifstream& configFile, char pole ); // чтение настроек из взятой из файла строки
    char makeSym();
};



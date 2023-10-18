#pragma once

#include <cstdint>
#include <string>
#include <fstream>


class DataGenerator {
public:

    DataGenerator();

    void readConfig( const std::string& filename );
    void writeToFile( std::string& path ); // запись исходной последовательности в файл
    uint32_t getN() {
        return N;
    }

private:

    uint16_t N = 50; // максимальная длина пакета в байтах, задается в config
    char sym = '@';
    uint32_t k = 100; // количество строк
    void getValue( std::ifstream& configFile, char pole );

};



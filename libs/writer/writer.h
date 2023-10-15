#ifndef WRITER_H
#define WRITER_H

#include <cstdint>
#include <string>
#include <fstream>
#include <vector>

class Writer {
public:

    Writer();

    void readConfig();
    void genData();
    void pack();
    void writeToFile( std::string& path ); // запись исходной последовательности в файл


private:

    uint32_t N = 110; // максимальная длина пакета в байтах, задается в config
    char sym = '>';
    uint32_t k = 100; // количество строк
    void getValue( std::ifstream& configFile, char pole );
    std::vector< uint32_t > data;

};

#endif // WRITER_H

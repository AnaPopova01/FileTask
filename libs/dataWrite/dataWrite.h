#pragma once
#include <cstdint>
#include <string>
#include <fstream>

class DataWrite {

public:

    DataWrite( std::string& path, uint16_t Num = 60 ); // const + change names of poles
    void writeFile( std::string& outpath ); // читаем файл //const



private:

    std::string origpath; // path to originCode
    std::ofstream outfile; // path to file for writing data
    uint16_t N; // max length of packet
    bool mixFlag = 0; // on/of mix of write data

    // размер служебных полей
    uint8_t k_in_1stHead = 4; // amount of symbols in 1st part of header info
    uint8_t k_in_2ndHead = 4;
    uint8_t k_in_data = 3;


    // текущие значения служебных полей
    // значение подзаголовка символа считается в addInfo и не имеет специального поля
    uint32_t currpackNum = 0; // current serial numder of pack, need to write header info, (0:max_num(k_in_1sthead))
    uint16_t kOfSym = 0; // amount of symbols in current packet
    uint16_t spaceInPack; // сколько свободного места [количество символов] для данных осталось в пакете
    std::string data; // this string without header and it written to output file


    void formPack( std::string& str );
    void addInfo( std::string& str );
    void printHeadInfo();
    void nextPacket();
    void resetPackSpace( uint16_t newSpace );
    void resetPackSpace();
    void printPack();
    void setkOfSym( uint16_t newK  );
};



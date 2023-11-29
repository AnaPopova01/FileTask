#pragma once
#include <cstdint>
#include <string>
#include <fstream>
#include "ipacker.h"

#include <map>
#include <vector>
#include <iostream>

class BaseImpl: public IPacker {

public:

    BaseImpl( PackerType type );
    void writeToFile() override {
        std::cerr << "cringe from Base" << std::endl;
    }
    void writeToFile( const std::string& inputfile, const std::string& outputfile, Protocol& prot ) override final;
    void getKey() override final {
        std::cerr << keyword;
    }

protected:

    int amountOfSym = 0;
    PackerType pack_type;
    Protocol prot { ProtocolType::Standart,  50, 0 };

    // размер служебных полей
    uint8_t headerSize = 0;
    uint8_t k_in_1stHead = 4; // кол-во символов для кодирования порядкового номера пакета
    uint8_t k_in_2ndHead = 4; // кол-во символов для кодирования длины пакета
    uint8_t k_in_data = 4; // кол-во символов для кодирования порядкового номера символа в строке
    unsigned int keyword = 0xDED;

    std::ofstream outfile; // path to file for writing data
    std::ifstream infile;
    // uint16_t N; // max length of packet

    // текущие значения служебных полей
    // значение подзаголовка символа считается в addInfo и не имеет специального поля
    uint32_t currpackNum = 0; // текущий порядковый номер пакета (0:max_num(k_in_1sthead))
    uint16_t kOfSym = 0; // кол-во символов в текущем пакете
    uint16_t spaceInPack = 0; // сколько свободного места [количество символов] для данных осталось в пакете
    uint16_t maxSpace = 0; // максимальный размер для данных
    std::string data = ""; // данные без заголовка

    std::map< std::int16_t, std::string > strdata;
    std::vector< std::string > vecdata; // вектор пакетов для их перемешивания

    void formPack();
    void addInfo(); //
    void addHeadInfo( std::string& str ); // заголовок печатается отдельно от данных
    void nextPacket();
    void resetPackSpace( uint16_t newSpace );
    void resetPackSpace();
    void setProtocol( Protocol& protocol );
    void finishPack( std::string& str ); //
    void setkOfSym( uint16_t newK  );
    void printvecdata();
    void printString( std::string& str );
};

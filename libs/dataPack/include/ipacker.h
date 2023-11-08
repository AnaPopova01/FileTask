#pragma once
#include <cstdint>
#include <iostream>
#include <fstream>

using std::string;

enum class ProtocolType : uint32_t { Standart = 0, Magic = 1 };

struct Protocol {

    ProtocolType type;
    uint16_t N; // max length of packet
    bool mixPackets = 0;
};



class IPacker {
public:

    virtual void writeToFile( const string& inputfile, const string& outputfile, Protocol& prot ) = 0;

};



class BaseImpl: public IPacker {

public:


    void writeToFile() {
        std::cerr << "cringe from Base" << std::endl;
    }
    virtual void writeToFile( const string& inputfile, const string& outputfile, Protocol& prot ) = 0;

protected:


    Protocol prot;
    // размер служебных полей
    uint8_t k_in_1stHead = 4; // кол-во символов для кодирования порядкового номера пакета
    uint8_t k_in_2ndHead = 4; // кол-во символов для кодирования длины пакета
    uint8_t k_in_data = 3; // кол-во символов для кодирования порядкового номера символа в строке
    unsigned int keyword = 0xBABADEDA;


    std::ofstream outfile; // path to file for writing data
    // uint16_t N; // max length of packet

    // текущие значения служебных полей
    // значение подзаголовка символа считается в addInfo и не имеет специального поля
    uint32_t currpackNum = 0; // текущий порядковый номер пакета (0:max_num(k_in_1sthead))
    uint16_t kOfSym = 0; // кол-во символов в текущем пакете
    uint16_t spaceInPack; // сколько свободного места [количество символов] для данных осталось в пакете
    std::string data; // данные без заголовка


};

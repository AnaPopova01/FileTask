#pragma once
#include <cstdint>
#include <iostream>
#include <fstream>
#include <vector>

using std::string;

enum class ProtocolType : uint32_t { Standart = 0, Magic = 1 };
// Standart - добавляет подзаголовок к данным и выравнивает пакет до фиксированной длины, заголовок состоит только из порядкового номера пакета
// Magic - добавляет подзаголовок к данным,заголовок состоит ключевого слова, порядкового номера пакета и его длины

struct Protocol {

    ProtocolType type;
    uint16_t N; // max length of packet
    bool mixPackets = 0;
};



class IPacker {
public:
    virtual void writeToFile() = 0;
    virtual void writeToFile( const string& inputfile, const string& outputfile, Protocol& prot ) = 0;
    virtual void getKey() = 0;

};



class BaseImpl: public IPacker {

public:


    void writeToFile()override {
        std::cerr << "cringe from Base" << std::endl;
    }
    virtual void writeToFile( const string& inputfile, const string& outputfile, Protocol& prot ) = 0;
    void getKey() override {
        std::cerr << keyword;
    }

protected:


    int amountOfSym = 0;

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
    string data = ""; // данные без заголовка
    std::vector< string > vecdata; // вектор пакетов для их перемешивания

};

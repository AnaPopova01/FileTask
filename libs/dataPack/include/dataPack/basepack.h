#pragma once
#include <cstdint>
#include <string>
#include <fstream>
#include "ipacker.h"
#include <math.h>
#include <map>
#include <vector>
#include <iostream>

class BaseImpl: public IPacker {

public:

    void packProcessing( const std::string& inputfile, const std::string& outputfile, Protocol& prot );


protected:

    PackerType type;
    Protocol prot;

    // размер служебных полей
    uint8_t headerSize = 0;
    uint8_t k_in_1stHead = 4; // кол-во символов для кодирования порядкового номера пакета
    uint8_t k_in_2ndHead = 4; // кол-во символов для кодирования длины пакета
    uint8_t serviceDataFieldLen = 4; // кол-во символов для кодирования порядкового номера символа в строке


    std::ofstream outfile; // path to file for writing data

    // текущие значения служебных полей
    // значение подзаголовка символа считается в addInfo и не имеет специального поля
    uint32_t currpackNum = 0; // текущий порядковый номер пакета (0:max_num(k_in_1sthead))
    uint16_t kOfSym = 0; // кол-во символов в текущем пакете
    uint16_t spaceInPack = 0; // сколько свободного места [количество символов] для данных осталось в пакете
    uint16_t maxSpace = 0; // максимальный размер для данных
    std::string data = ""; // данные без заголовка

    std::vector< std::string > vecdata; // вектор пакетов для их перемешивания
    std::map< std::uint16_t, std::string > strdata;


    void readFromFile( const std::string& inputfile );
    virtual void writeToFile( const std::string& outputfile ) = 0;

    void formPack();
    void addInfo(); //
    virtual void addHeadInfo( std::string& str ) = 0; // заголовок печатается отдельно от данных
    void nextPacket();
    void resetPackSpace( uint16_t newSpace );
    void  resetPackSpace();
    virtual void setProtocol( Protocol& protocol ) = 0;
    virtual void finishPack( std::string& str ) = 0; //
    void setkOfSym( uint16_t newK  );
    void printvecdata();
    void printString( std::string& str );
};

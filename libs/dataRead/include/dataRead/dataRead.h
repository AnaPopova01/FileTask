#pragma once

#include <cstdint>
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <map>

using std::string;
using std::vector;



class DataRead {

public:


    void readFromFile( const string& inputfile, const string& outputfile );

private:


    void getProtInfo();
    void divideHeadFromInfo();
    void isMixed();
    void cleanData();
    void printData();
    void printPack();



    // protocol
    uint16_t N = 50; // max length of packet
    bool stdProt = 1;
    bool mixFlag = 0;

    std::ofstream outfile;
    std::ifstream infile;

    string data;
    uint8_t k_in_data = 4; // кол-во символов для кодирования порядкового номера символа в строке
    uint8_t headerSize = 4;
    unsigned int keyword = 0xDED;
    uint8_t k_in_1stHead = 4; // кол-во символов для кодирования порядкового номера пакета
    uint8_t k_in_2ndHead = 4; // кол-во символов для кодирования длины пакета

    std::map< std::int16_t, string > strdata;

    uint16_t numCurrSym = 0;
    uint16_t kOfPackets = 0;
    bool nextStr = 0;
};



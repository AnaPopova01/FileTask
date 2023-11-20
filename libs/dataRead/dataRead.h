#pragma once

#include <cstdint>
#include <string>
#include <fstream>
#include <vector>
#include <iostream>

using std::string;

class DataRead {

public:

    DataRead();

    void readFromFile( const string& inputfile, const string& outputfile );

private:

    void getProtInfo();
    void divideHeadFromInfo();
    void isMixed();
    void cleanData();
    void printData();
    void printPack();

    std::ofstream outfile;
    std::ifstream infile;
    std::vector< int16_t > intdata;
    std::vector< string > strdata;
    uint8_t headerSize = 4;
    bool stdProt = 1;
    bool mixFlag = 0;
    uint16_t numCurrSym = 0;
    uint16_t kOfPackets = 0;
    bool nextStr = 0;
};



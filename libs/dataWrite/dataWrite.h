#pragma once
#include <cstdint>
#include <string>
#include <fstream>

class DataWrite {

public:

    DataWrite( std::string& path, uint16_t Num );
    void writeFile( std::string& outpath ); // читаем файл



private:
    uint16_t N; // max length of packet
    std::string origpath; // path to originCode
    uint32_t currpackNum = 0; // current serial numder of pack
    uint8_t sizeOfHeaderInfo = 8;
    uint16_t spaceInPack; // how much free space in packet unclude header info (8 char)
    bool newPackFlag = 1;
    std::string data;
    uint16_t kOfSym = 0;

    std::ofstream outfile;
    void formPack( std::string& str );
    void addInfo( std::string& str );
    void printHeadInfo();
    void nextPacket();
    void resetPackSpace( uint16_t newSpace );
    void resetPackSpace();
    void printPack();
    void setkOfSym( uint16_t newK  );
};



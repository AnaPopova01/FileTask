#ifndef ALIGNEDPACKER_H
#define ALIGNEDPACKER_H
#include "ipacker.h"
#include "basepack.h"
#include <thread>

class StandartProt: public BaseImpl {
public:
    StandartProt( PackerType prtype ) {
        this->type = prtype;
    }


private:

    void printData();
    std::string toFinishPack(std::string subStr , uint16_t i);
    int getPacketsCount();
    void alignData();
    std::string addServiceInfo( std::string subStr, int symCount );
    uint16_t getSubstrLen();
    std::string createOnePacket( uint16_t i );

    std::vector< std::thread > threads;


    void setProtocol( Protocol& protocol ) override final;
    void writeToFile( const std::string& outputfile ) override final;
    void finishPack( std::string& str ) override final;
    void addInfo();
    void addHeadInfo( std::string& str );
};

#endif // ALIGNEDPACKER_H

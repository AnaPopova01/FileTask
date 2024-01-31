#ifndef ALIGNEDPACKER_H
#define ALIGNEDPACKER_H
#include "ipacker.h"
#include "basepack.h"
#include <thread>
#include <future>
#include "threadPool/threadpool.h"
#include <functional>


using std::string;
using std::vector;
using std::promise;
using std::future;
using std::ref;

class StandartProt: public BaseImpl {
public:
    StandartProt( PackerType prtype ) {
        this->type = prtype;
    }
    friend class ThreadPool;

private:

    void printData();
    string toFinishPack( string subStr, uint16_t i, uint16_t spaceInPack, uint8_t k_in_1stHead );
    int getPacketsCount();
    void alignData();
    string addServiceInfo( string subStr );
    uint16_t getSubstrLen();
    static string makeOnePack( const uint16_t idOfPacket, string subStr, const uint16_t freeSpaceInPack, const uint8_t amountOfSymIn1Header );
    void writeNoThread();
    void writeThread();

    vector< std::thread > threads;


    void setProtocol( Protocol& protocol ) override final;
    void writeToFile( const std::string& outputfile ) override final;
    void finishPack( std::string& str ) override final;
    void addInfo();
    void addHeadInfo( std::string& str );
};

#endif // ALIGNEDPACKER_H

#pragma once
#include <cstdint>
#include <string>
#include <fstream>
#include "include/ipacker.h"


class RandomImpl: public BaseImpl {

public:

    // using BaseImpl::BaseImpl;

    void writeToFile() {
        std::cerr << "wtf from random" << std::endl;
    }

    virtual void writeToFile( const string& inputfile, const string& outputfile, Protocol& prot ) override final;


private:

    void formPack( std::string& str );
    void addInfo( std::string& str ); //
    void printHeadInfo(); // заголовок печатается отдельно от данных
    void nextPacket();
    void resetPackSpace( uint16_t newSpace );
    void resetPackSpace();
    void setProtocol( Protocol& protocol );
    void printPack(); //
    void setkOfSym( uint16_t newK  );

    void getString();

};





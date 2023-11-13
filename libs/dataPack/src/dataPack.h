#pragma once
#include <cstdint>
#include <string>
#include <fstream>
#include "include/ipacker.h"




class AlignedImpl: public BaseImpl {

public:

    // using BaseImpl::BaseImpl;
// void writeToFile() {
// std::cerr << "wtf from Aligned" << std::endl;
// }
    virtual void writeToFile( const string& inputfile, const string& outputfile, Protocol& protocol ) override final;




private:

    void formPack( std::string& str );
    void addInfo( std::string& str ); //
    void printHeadInfo(); // заголовок печатается отдельно от данных
    void nextPacket();
    void resetPackSpace( uint16_t newSpace );
    void setProtocol( Protocol& protocol );
    void printPack(); //
    void setkOfSym( uint16_t newK  );


};



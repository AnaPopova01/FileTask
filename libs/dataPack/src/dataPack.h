#pragma once
#include <cstdint>
#include <string>
#include <fstream>
#include "include/ipacker.h"
#include <cmath>




class AlignedImpl: public BaseImpl {

public:

    using BaseImpl::BaseImpl;
    void writeToFile() {
        std::cerr << "wtf from Aligned" << std::endl;
    }
    virtual void writeToFile( const string& inputfile, const string& outputfile, Protocol& protocol ) override final;




private:


    void formPack();
    void addInfo(); //
    void addHeadInfo( string& str ); // заголовок печатается отдельно от данных
    void nextPacket();
    void resetPackSpace( uint16_t newSpace );
    void resetPackSpace();
    void setProtocol( Protocol& protocol );
    void finishPack( string& str ); //
    void setkOfSym( uint16_t newK  );
    void printvecdata();
    void printString( string& str );


};



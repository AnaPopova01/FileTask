#pragma once
#include <cstdint>
#include <string>
#include <fstream>
#include "include/ipacker.h"




class AlignedImpl: public BaseImpl {

public:

    using BaseImpl::BaseImpl;

    void writeToFile() override {
        std::cerr << "wtf from Aligned" << std::endl;
    }



private:

// void formPack( std::string& str );
// void addInfo( std::string& str ); //
// void printHeadInfo(); // заголовок печатается отдельно от данных
// void nextPacket();
// void resetPackSpace( uint16_t newSpace );
// void resetPackSpace();
// void printPack(); //
// void setkOfSym( uint16_t newK  );
};



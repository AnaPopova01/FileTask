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

    virtual void writeToFile( const string& inputfile, const string& outputfile, Protocol& prot ) override final {
        std::cerr << "lol" << std::endl;
    }


};





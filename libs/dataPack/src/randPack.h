#pragma once
#include <cstdint>
#include <string>
#include <fstream>
#include "include/ipacker.h"


class RandomImpl: public BaseImpl {

public:

    using BaseImpl::BaseImpl;
    void writeToFile() override {
        std::cerr << "wtf from random" << std::endl;
    }




};





#pragma once
#include "ipacker.h"
#include <iostream>
#include <memory>
#include <fstream>

using std::cerr;
using std::cin;
using std::endl;


std::unique_ptr< IPacker > createPackerImpl(); // make Impl using console

std::unique_ptr< IPacker > createPackerImpl( PackerType type );

ProtocolType getProtocolType();

Protocol getProtocol();

PackerType getPackerType();

bool isInRange( uint32_t value, uint32_t left, uint32_t right );







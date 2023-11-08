#pragma once
#include "ipacker.h"
#include <iostream>
#include <memory>
#include "src/dataPack.h"
#include "src/randPack.h"

using std::cerr;
using std::cin;
using std::endl;


enum class PackerType : uint32_t { Aligned = 0, Random = 1 };


bool isInRange( uint32_t value, uint32_t left, uint32_t right ) {
    return value >= left && value <= right;
}

PackerType getPackerType() {

    cerr << "creating packer" << endl;
    cerr << "insert value in range [" << static_cast< uint32_t >( PackerType::Aligned ) << "," << static_cast< uint32_t >( PackerType::Random ) << "]" << endl;
    cerr << "where" << "\t" << static_cast< uint32_t >( PackerType::Aligned ) << " - Aligned";
    cerr << "\t" << static_cast< uint32_t >( PackerType::Random ) << " - Random" << endl;
    uint32_t value;
    cin >> value;
    return isInRange( value, static_cast< uint32_t >( PackerType::Aligned ), static_cast< uint32_t >( PackerType::Random ) ) ? static_cast< PackerType >( value ) : getPackerType();

}

ProtocolType getProtocolType() {

    cerr << "choose protocol" << endl;
    cerr << "insert value in range [" << static_cast< uint32_t >( ProtocolType::Standart ) << "," << static_cast< uint32_t >( ProtocolType::Magic ) << "]" << endl;
    cerr << "where" << "\t" << static_cast< uint32_t >( ProtocolType::Standart ) << " - Standart";
    cerr << "\t" << static_cast< uint32_t >( ProtocolType::Magic ) << " - Magic" << endl;
    uint32_t value;
    cin >> value;

    return isInRange( value, static_cast< uint32_t >( ProtocolType::Standart ), static_cast< uint32_t >( ProtocolType::Magic ) ) ? static_cast< ProtocolType >( value ) : getProtocolType();
}
Protocol getProtocol() {

    uint16_t maxLength;
    bool mixfFlag;

    auto type = getProtocolType();
    cerr << "enter max length of packet" << endl;
    cin >> maxLength;
    cerr << "enter enable(1) or disable(0) mixing" << endl;
    cin >> mixfFlag;
    Protocol prot { type, maxLength, mixfFlag };
    cerr << "-----------------------------------------------------" << endl;
    cerr << "packer created!" << endl;
    return prot;
}


std::unique_ptr< IPacker > createPackerImpl() {

    PackerType type = getPackerType();
    std::unique_ptr< IPacker > ret;

    switch( type ) {
    case PackerType::Aligned:
        ret = std::make_unique< AlignedImpl >();
        break;
    case PackerType::Random:
        ret = std::make_unique< RandomImpl >();
        break;
    default:
        throw std::runtime_error( " unsupported printer type " + std::to_string( static_cast< int >( type ) ) );
        break;
    }

    return ret;
}

std::unique_ptr< IPacker > createPackerImpl( PackerType type ) {

    std::unique_ptr< IPacker > ret;

    switch( type ) {
    case PackerType::Aligned:
        ret = std::make_unique< AlignedImpl >();
        break;
    case PackerType::Random:
        ret = std::make_unique< RandomImpl >();
        break;
    default:
        throw std::runtime_error( " unsupported printer type " + std::to_string( static_cast< int >( type ) ) );
        break;
    }

    return ret;
}




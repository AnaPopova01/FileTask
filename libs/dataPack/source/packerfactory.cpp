#include "dataPack/packerfactory.h"
#include "dataPack/basepack.h"
#include "dataPack/magicprot.h"
#include "dataPack/standartprot.h"


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
    Protocol prot { maxLength, mixfFlag }; // deleted type argument
    cerr << "-----------------------------------------------------" << endl;
    cerr << "packer created!" << endl;
    return prot;
}


// std::unique_ptr< IPacker > createPackerImpl() {

// PackerType type = getPackerType();
// std::unique_ptr< IPacker > ret;

// switch( type ) {
// case PackerType::Aligned:
// ret = std::make_unique< protType >( PackerType::Aligned );
// break;
// case PackerType::Random:
// ret = std::make_unique< protType >( PackerType::Random );
// break;
// default:
// throw std::runtime_error( " unsupported packer type " + std::to_string( static_cast< int >( type ) ) );
// break;
// }

// return ret;
// }

std::unique_ptr< IPacker > createPackerImpl( PackerType type, ProtocolType protType ) {

    std::unique_ptr< IPacker > ret;


    switch( protType ) {
    case ProtocolType::Standart:
        ret = std::make_unique< StandartProt >( type );
        break;
    case ProtocolType::Magic:
        ret = std::make_unique< MagicProt >( type );
        break;
    default:
        throw std::runtime_error( " unsupported packer type " );
        break;
    }

    return ret;
}






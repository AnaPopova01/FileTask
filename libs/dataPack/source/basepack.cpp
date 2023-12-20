#include "dataPack/basepack.h"

void BaseImpl::packProcessing( const std::string& inputfile, const std::string& outputfile, Protocol& protocol ) {

    setProtocol( protocol );

    readFromFile( inputfile );

    writeToFile( outputfile );

}

void BaseImpl::readFromFile( const std::string& inputfile ) {

    std::ifstream originFile( inputfile, std::ios::binary ); // open file with origin data
    char value = 'z';
    int count = 0;

    if( !originFile.is_open() ) {

        throw std::runtime_error( "cant open input packer file" );

    } else {

        while( !originFile.eof() ) {

            originFile.read( ( char* )&value, sizeof( char ) );
            count++;
            // std::cerr << count << ") val = " << value << "\n"; // это пробел
            data += value;

        }
        data.erase( data.size() - 1, 1 );
    }

}



void BaseImpl::resetPackSpace() {

    switch( type ) {

    case PackerType::Aligned:

        this->spaceInPack = maxSpace;
        break;

    case PackerType::Random:



        this->spaceInPack = serviceDataFieldLen + 1 + ( 1 + rand() % ( prot.N - ( headerSize + serviceDataFieldLen + 1 ) ) );
        // std::cerr << "spaceInPack = " << spaceInPack << "\n";
        break;
    }
}




void BaseImpl::formPack() {

    uint16_t length = data.size();
    std::string str;

    if( length > spaceInPack ) {


        uint16_t kOfPacket = ( spaceInPack / ( serviceDataFieldLen + 1 ) ); // какое количество пакетов можно добавить в текущую строку
        setkOfSym( kOfPacket );
        for( uint16_t i = 0; i < kOfPacket * ( serviceDataFieldLen + 1 ); i++ ) {
            str = str + data[ i ];
        }
        data.erase( 0, kOfPacket * ( serviceDataFieldLen + 1 ) );
        finishPack( str );
        nextPacket();
        if( data.size() != 0 ) {
            formPack();
        }

    } else if( length < spaceInPack ) {


        setkOfSym( length / ( this->serviceDataFieldLen + 1 ) );
        str = data + str;
        resetPackSpace( spaceInPack - length );
        finishPack( str );

    } else if( length == spaceInPack ) {
        setkOfSym( length / ( this->serviceDataFieldLen + 1 ) );
        str = data + str;

        finishPack( str );


    }

}

void BaseImpl::nextPacket() {

    this->currpackNum++;
    resetPackSpace();
    this->kOfSym = 0;

}



void BaseImpl::printString( std::string& str ) {

    for( uint16_t i = 0; i < str.size(); i++ ) {
        outfile.write( ( char* )( &str[ i ] ), sizeof( char ) );
        // std::cerr << str[ i ];
    }
    std::cerr << "\n";
}

void BaseImpl::printvecdata() {
    auto size = vecdata.size();
    int x = 0;

    for( uint16_t i = 0; i < size; i++ ) {

        if( prot.mixPackets == 1 ) {
            if( vecdata.size() != 1 ) {
                auto index { vecdata.begin() };
                x = { rand() % ( vecdata.size() - 1 ) };
                printString( vecdata[ x ] );
                vecdata.erase( index + x );
            } else {

                printString( vecdata[ 0 ] );

            }
        } else {

            printString( vecdata[ i ] );
            // outfile << "\n";

        }
        // if( i != size - 1 ) {
        // outfile << "\n";
        // }
    }
}


void BaseImpl::resetPackSpace( uint16_t newSpace  ) {

    this->spaceInPack = newSpace;
}


void BaseImpl::setkOfSym( uint16_t newK  ) {

    this->kOfSym += newK;
}








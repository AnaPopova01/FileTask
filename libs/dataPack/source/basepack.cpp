#include "dataPack/basepack.h"

BaseImpl::BaseImpl( PackerType type ) {


    this->pack_type = type;
}

void BaseImpl::writeToFile( const std::string& inputfile, const std::string& outputfile, Protocol& protocol ) {

    setProtocol( protocol );

    std::ifstream originFile( inputfile, std::ios::binary ); // open file with origin data

    if( !originFile.is_open() ) {

        throw std::runtime_error( "cant open INPUT file " );

    } else {

        this->outfile.open( outputfile, std::ios::binary ); // open file to write
        if( !outfile.is_open() ) {

            throw std::runtime_error( "cant open OUTPUT file " );

        } else {

            char value;
            int count = 0;

            while( !originFile.eof() ) {

                originFile.read( ( char* )&value, sizeof( char ) );
                count++;
                // std::cerr << count << ") val = " << value << "\n"; // это пробел
                data += value;


            }
            data.erase( data.size() - 1, 1 );
            // std::cerr << "amount sym in origdata = " << count - 1 << "\n";
            // std::cerr << "the last = " << value << "\n"; // это пробел


            if( prot.type == ProtocolType::Standart ) {

                addInfo();// добавляем служебную информацию
            }

            // float amount_of_packs = ( prot.N - headerSize ) / ( k_in_data + 1 );
            // std::cerr << "amount of string = " <<  ceil( data.size() / ( k_in_data + 1 ) / amount_of_packs ) << std::endl;

            formPack();
            printvecdata();
            outfile.close();
        }

    }

}

void BaseImpl::formPack() {

    uint16_t length = data.size();
    std::string str;

    if( length > spaceInPack ) {


        uint16_t kOfPacket = ( spaceInPack / ( k_in_data + 1 ) ); // какое количество пакетов можно добавить в текущую строку
        setkOfSym( kOfPacket );
        for( uint16_t i = 0; i < kOfPacket * ( k_in_data + 1 ); i++ ) {
            str = str + data[ i ];
        }
        data.erase( 0, kOfPacket * ( k_in_data + 1 ) );
        finishPack( str );
        nextPacket();
        if( data.size() != 0 ) {
            formPack();
        }

    } else if( length < spaceInPack ) {


        setkOfSym( length / ( this->k_in_data + 1 ) );
        str = data + str;
        resetPackSpace( spaceInPack - length );
        finishPack( str );

    } else if( length == spaceInPack ) {
        setkOfSym( length / ( this->k_in_data + 1 ) );
        str = data + str;

        finishPack( str );
        // nextPacket();

    }

}

void BaseImpl::nextPacket() {

    this->currpackNum++;
    resetPackSpace();
    this->kOfSym = 0;

}

void BaseImpl::finishPack( std::string& str ) { // also add pack to common vector

    if( prot.type == ProtocolType::Standart ) {
        while( str.size() < maxSpace ) {
            str = str + "&";
        }
    }
    addHeadInfo( str );
    vecdata.push_back( str );
}

void BaseImpl::printString( std::string& str ) {

    for( uint16_t i = 0; i < str.size(); i++ ) {
        outfile.write( ( char* )( &str[ i ] ), sizeof( char ) );
    }
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

void BaseImpl::resetPackSpace() {

    switch( pack_type ) {

    case PackerType::Aligned:

        this->spaceInPack = maxSpace;
        break;

    case PackerType::Random:
        // srand( time( NULL ) );

        this->spaceInPack = k_in_data + 1 + ( 1 + rand() % ( prot.N - ( headerSize + k_in_data + 1 ) ) );
        break;
    }
}

void BaseImpl::setkOfSym( uint16_t newK  ) {

    this->kOfSym += newK;
}



void BaseImpl::addInfo() {

    std::string payloadheader;
    uint16_t endOfStr = data.size();

    for( uint16_t i = 0; i < endOfStr; i++ ) {

        payloadheader = std::to_string( i );
        while( payloadheader.size() < this->k_in_data ) {
            payloadheader = "0" + payloadheader;
        }
        data.insert( i * ( k_in_data + 1 ), payloadheader );
    }
}

void BaseImpl::addHeadInfo( std::string& str ) {

    if( prot.type == ProtocolType::Standart ) {

        std::string header1 = std::to_string( currpackNum );
        while( header1.size() != k_in_1stHead ) {
            header1 = "0" + header1;
        }
        str = header1 + str;
        // outfile << header1 << "\t";
    }
    if( prot.type == ProtocolType::Magic ) {

        std::string header = std::to_string( keyword );
        std::string header1 = std::to_string( currpackNum );
        while( header1.size() != k_in_1stHead ) {
            header1 = "0" + header1;
        }
        std::string header2 = std::to_string( kOfSym );
        while( header2.size() != k_in_2ndHead ) {
            header2 = "0" + header2;
        }
        str = header + header1 + header2 + str;
        // outfile << header << "\t" << header1 << "\t" << header2 << "\t";
    }

}

void BaseImpl::setProtocol( Protocol& protocol ) {
    this->prot = protocol;
    if( prot.type == ProtocolType::Standart ) {

        headerSize = this->k_in_1stHead;

    }
    if( prot.type == ProtocolType::Magic ) {

        headerSize = k_in_1stHead + k_in_2ndHead + ( std::to_string( keyword ) ).size();
        k_in_data = 0;

    }
    this->maxSpace = prot.N - headerSize;

    resetPackSpace();
}



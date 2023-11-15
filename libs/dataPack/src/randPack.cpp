#include "randPack.h"

void RandomImpl::writeToFile( const string& inputfile, const string& outputfile, Protocol& protocol ) {

    setProtocol( protocol );


    std::ifstream originFile( inputfile ); // open file with origin data

    if( !originFile.is_open() ) {

        throw std::runtime_error( "cant open file " );

    } else {

        this->outfile.open( outputfile ); // open file to write
        if( !outfile.is_open() ) {

            throw std::runtime_error( "cant open file " );

        } else {

            std::string str;

            while( !originFile.eof() ) { // until file finish

                std::getline( originFile, str ); // read string
                addInfo( str ); // добавляем служебную информацию
                formPack( str ); // write to file

            }
            printvecdata();

            outfile.close(); // close file
        }

    }
}


void RandomImpl::formPack( std::string& str ) {

    uint16_t length = str.size();


    if( length > spaceInPack ) { // проверка влезет ли строка в пакет


        uint16_t kOfPacket = ( spaceInPack / ( k_in_data + 1 ) ); // какое количество пакетов можно добавить в текущую строку
        setkOfSym( kOfPacket );
        for( uint16_t i = 0; i < kOfPacket * ( k_in_data + 1 ); i++ ) {
            data = data + str[ i ];
        }
        str.erase( 0, kOfPacket * ( k_in_data + 1 ) );


        printPack();
        nextPacket();
        if( str.size() != 0 ) {
            formPack( str );
        }
        ;

        // если не влезает то делим на две - одну пишем в файл, другой вызываем formPack

    } else if( length < spaceInPack ) {

        setkOfSym( length / ( this->k_in_data + 1 ) );
        data = data + str;

        resetPackSpace( spaceInPack - length );

    } else if( length == spaceInPack ) {// пишем в файл и (номер пакета) ++

        setkOfSym( length / ( this->k_in_data + 1 ) );
        data = data + str;

        printPack();
        nextPacket();


    }

}

void RandomImpl::nextPacket() {

    this->currpackNum++;
    // newPackFlag = true;
    resetPackSpace();

    this->kOfSym = 0;
    this->data = "";
}

void RandomImpl::printPack() {

// if( this->currpackNum != 0 ) {
// outfile << "\n";
// }
// ;
    if( prot.type == ProtocolType::Standart ) {
        while( data.size() < prot.N - k_in_1stHead ) {
            data = data + "&";
        }
    }
    printHeadInfo();
    vecdata.push_back( data );
// for( uint16_t i = 0; i < data.size(); i++ ) {

// outfile << data[ i ];

// }
}

void RandomImpl::printString( std::string& str ) {

    for( uint16_t i = 0; i < str.size(); i++ ) {
        outfile << str[ i ];

    }
}

void RandomImpl::printvecdata() {
    auto size = vecdata.size();
    int x = 0;

    for( int i = 0; i < size; i++ ) {

        if( prot.mixPackets == 1 ) {
            if( vecdata.size() != 1 ) {
                auto index { vecdata.begin() };
                x = { rand() % ( vecdata.size() - 1 ) };

                printString( vecdata[ x ] );

                // std::cerr << vecdata[ x ] << "\n";

                vecdata.erase( index + x );
            } else {

                printString( vecdata[ 0 ] );
                // std::cerr << vecdata[ 0 ];
            }
        } else {

            printString( vecdata[ i ] );
            // std::cerr << vecdata[ i ];


        }
        if( i != size - 1 ) {
            outfile << "\n";
        }
    }
}


void RandomImpl::resetPackSpace( uint16_t newSpace   ) {

    this->spaceInPack = newSpace;
}

void RandomImpl::resetPackSpace() {
    // srand( time( NULL ) );

    this->spaceInPack = k_in_data + 1 + ( 1 + rand() % ( prot.N - ( headerSize + k_in_data + 1 ) ) );
    // if Aligned then resetPackSpace( prot.N - this->k_in_1stHead )
}

void RandomImpl::setkOfSym( uint16_t newK  ) {

    this->kOfSym += newK;
}



void RandomImpl::addInfo( std::string& str ) {

    std::string payloadheader;
    uint16_t endOfStr = str.size();

    for( uint16_t i = 0; i < endOfStr; i++ ) {

        payloadheader = std::to_string( i );
        while( payloadheader.size() != this->k_in_data ) {
            payloadheader = "0" + payloadheader;
        }
        str.insert( i * ( k_in_data + 1 ), payloadheader );
    }
}

void RandomImpl::printHeadInfo() { // and add to data

    if( prot.type == ProtocolType::Standart ) {

        std::string header1 = std::to_string( currpackNum );
        while( header1.size() != k_in_1stHead ) {
            header1 = "0" + header1;
        }
        data = header1 + data;
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
        data = header + header1 + header2 + data;
        // outfile << header << "\t" << header1 << "\t" << header2 << "\t";
    }


}

void RandomImpl::setProtocol( Protocol& protocol ) {
    this->prot = protocol;
    prot.type == ProtocolType::Standart ? headerSize = 4 : headerSize = 12;
    resetPackSpace();

}




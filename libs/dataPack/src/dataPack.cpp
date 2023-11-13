#include "dataPack.h"

#include <iostream>


void AlignedImpl::writeToFile( const string& inputfile, const string& outputfile, Protocol& protocol ) {

    setProtocol( protocol );


    this->spaceInPack = 0;// resetPackSpace( prot.N - this->k_in_1stHead ); // - this->k_in_2ndHead;
    std::ifstream originFile( inputfile ); // open file with origin data

    if( !originFile.is_open() ) {

        throw std::runtime_error( "cant open file " );

    } else {

        this->outfile.open( outputfile ); // open file to write
        if( !outfile.is_open() ) {

            throw std::runtime_error( "cant open file " );

        } else {

            std::string str; // string for data

            while( !originFile.eof() ) { // until file finish


                // createPacket();
                // printPacket();
                std::getline( originFile, str ); // read string
                addInfo( str ); // добавляем служебную информацию
                formPack( str ); // write to file
            }

            outfile.close(); // close file
        }

    }
}

void AlignedImpl::formPack( std::string& str ) {

    uint16_t length = str.size();


    if( length > spaceInPack ) { // проверка влезет ли строка в пакет


        uint16_t kOfPacket = ( spaceInPack / ( k_in_data + 1 ) ); // какое количество пакетов можно добавить в текущую строку
        setkOfSym( kOfPacket );
        for( uint16_t i = 0; i < kOfPacket * ( k_in_data + 1 ); i++ ) {
            data = data + str[ i ];
        }
        str.erase( 0, kOfPacket * ( k_in_data + 1 ) );
        while( data.size() < prot.N - k_in_1stHead ) {
            data = data + "&";
        }
        printPack();
        nextPacket();
        formPack( str );

        // если не влезает то делим на две - одну пишем в файл, другой вызываем printPack

    } else if( length < spaceInPack ) {

        setkOfSym( length / this->k_in_data + 1 );
        data = data + str;
        // newPackFlag = false; // useless
        resetPackSpace( spaceInPack - length );

    } else if( length == spaceInPack ) {// пишем в файл и (номер пакета) ++

        setkOfSym( length / this->k_in_data + 1 );
        data = data + str;

        printPack();
        nextPacket();


    }

}

void AlignedImpl::nextPacket() {

    this->currpackNum++;
    // newPackFlag = true;
    this->spaceInPack = prot.N - k_in_1stHead;// - k_in_2ndHead;
    this->kOfSym = 0;
    this->data = "";
}

void AlignedImpl::printPack() {

    if( this->currpackNum != 0 ) {
        outfile << "\n";
    }
    ;
    printHeadInfo();
    for( uint16_t i = 0; i < data.size(); i++ ) {
        outfile << data[ i ];

    }
}

void AlignedImpl::resetPackSpace( uint16_t newSpace  ) {

    this->spaceInPack = newSpace;
}

void AlignedImpl::setkOfSym( uint16_t newK  ) {

    this->kOfSym += newK;
}



void AlignedImpl::addInfo( std::string& str ) {

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

void AlignedImpl::printHeadInfo() {

    std::string header1 = std::to_string( currpackNum );
    while( header1.size() != k_in_1stHead ) {
        header1 = "0" + header1;
    }
    outfile << header1; // << "\t";

}

void AlignedImpl::setProtocol( Protocol& protocol ) {
    this->prot = protocol;
}


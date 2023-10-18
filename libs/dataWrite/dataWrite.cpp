#include "dataWrite.h"
#include <iostream>

DataWrite::DataWrite( std::string& path, uint16_t Num ) {
    this->N = Num;
    this->origpath = path;
    this->spaceInPack = Num - sizeOfHeaderInfo;
}

void DataWrite::writeFile( std::string& outpath ) {

    std::ifstream originFile( origpath ); // open file with origin strings
    if( !originFile.is_open() ) {

        throw std::runtime_error( "cant open file " );

    } else {

        this->outfile.open( outpath ); // open file to write
        std::string str; // string for data

        while( !originFile.eof() ) { // until file finish


            std::getline( originFile, str ); // read string
            addInfo( str ); // добавляем служебную информацию
            formPack( str ); // write to file
        }

        outfile.close(); // close file

    }
}

void DataWrite::formPack( std::string& str ) {

    uint16_t length = str.size();


    if( length > spaceInPack ) { // проверка влезет ли строка в пакет


        uint16_t kOfPacket = ( spaceInPack / 4 );
        setkOfSym( kOfPacket );
        for( uint16_t i = 0; i < kOfPacket * 4; i++ ) {
            data = data + str[ i ];
        }
        str.erase( 0, kOfPacket * 4 );
        while( data.size() < N - sizeOfHeaderInfo ) {
            data = data + "&";
        }
        printPack();
        nextPacket();
        formPack( str );

        // если не влезает то делим на две - одну пишем в файл, другой вызываем printPack

    } else if( length < spaceInPack ) {

        setkOfSym( length / 4 );
        data = data + str;
        // newPackFlag = false; // useless
        resetPackSpace( spaceInPack - length );

    } else if( length == spaceInPack ) {// пишем в файл и (номер пакета) ++

        setkOfSym( length / 4 );
        data = data + str;

        printPack();
        nextPacket();


    }

}

void DataWrite::nextPacket() {

    this->currpackNum++;
    // newPackFlag = true;
    this->spaceInPack = N - sizeOfHeaderInfo;
    this->kOfSym = 0;
    this->data = "";
}

void DataWrite::printPack() {

    printHeadInfo();
    for( uint16_t i = 0; i < data.size(); i++ ) {
        outfile << data[ i ];

    }
    outfile << "\n";
}

void DataWrite::resetPackSpace( uint16_t newSpace  ) {

    this->spaceInPack = newSpace;
}

void DataWrite::setkOfSym( uint16_t newK  ) {

    this->kOfSym += newK;
}



void DataWrite::addInfo( std::string& str ) {

    std::string payloadheader;
    uint16_t endOfStr = str.size();

    for( uint16_t i = 0; i < endOfStr; i++ ) {

        payloadheader = std::to_string( i );
        while( payloadheader.size() != 3 ) {
            payloadheader = "0" + payloadheader;
        }
        str.insert( i * 4, payloadheader );
    }
}

void DataWrite::printHeadInfo() {

    std::string header1 = std::to_string( currpackNum );
    while( header1.size() != 4 ) {
        header1 = "0" + header1;
    }
    outfile << header1 << "\t";


    std::string header2 = std::to_string( kOfSym );
    while( header2.size() != 4 ) {
        header2 = "0" + header2;
    }
    outfile << header2 << "\t";

}


// how empty space now?
// if less than length of string then divide string
// if divide is yes
// if divide is no


// вызвать для обеих функцию записи
// если нет то вызвать функцию записи

// функция записи
// добавить служебную инфу
// влезет ли строка в текущий пакет заданной длины с учетом служебной инфы?
// если да то записать в файл     если нет то разбить на подстроки, записать что влезет а остаток в следующий пакет

#include "dataGеn.h"
#include <iostream>

DataGеnerator::DataGеnerator() {

}

void DataGеnerator::readConfig() {

    std::ifstream configFile( "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/config.txt" ); // open file
    if( !configFile.is_open() ) {
        throw std::runtime_error( "cant open file " ); // если не получилось throw
    } else {

        // записать строку из файла
        // create string
        // find '='
        // delete until '='
        // write to fx  pole

        getValue( configFile, 'N' );
        getValue( configFile, 's' );
        getValue( configFile, 'k' );

    }

    configFile.close();
}

void DataGеnerator::getValue( std::ifstream& configFile, char pole ) {

    std::string str;
    std::getline( configFile, str );
    uint8_t pos = str.std::string::find( '=', 0 );
    str.std::string::erase( 0, pos + 1 );
    if( pole == 's' ) {
        this->sym = str [ 0 ];
    }
    if( pole == 'N' ) {
        this->N = std::stoi( str );
    }
    if( pole == 'k' ) {
        this->k = std::stoi( str );
    }

}


void DataGеnerator::writeToFile( std::string& path ) {

    srand( time( NULL ) );

    std::ofstream file( path );

    for( uint32_t numOfStr = 0; numOfStr < this->k; numOfStr++ ) {

        uint32_t l = 1 + rand() % ( 1 * N ); // set current length
        // file << l;

        for( uint32_t length = 0; length < l; length++ ) {
            file << sym;

        }
        if( numOfStr != this->k - 1 ) {
            file << "\n";
        }

    }


}


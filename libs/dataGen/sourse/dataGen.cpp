#include "dataGen/dataGen.h"
#include <iostream>


void DataGenerator::readConfig( const std::string& filename ) {

    std::ifstream configFile( filename ); // open file
    if( !configFile.is_open() ) {
        throw std::runtime_error( "cant open config file" ); // если не получилось throw
    } else {

        // записать строку из файла
        // create string
        // find '='
        // delete until '='
        // write to fx  pole

        getSett( configFile, 'N' );
        getSett( configFile, 's' );
        getSett( configFile, 'k' );

    }

    configFile.close();
}

void DataGenerator::getSett( std::ifstream& configFile, char pole ) {

    std::string str;
    std::getline( configFile, str );
    uint8_t pos = str.std::string::find( '=', 0 );
    str.std::string::erase( 0, pos + 1 );
    if( pole == 's' ) {
        this->sym = str [ 0 ];
    } else if( pole == 'N' ) {
        this->N = std::stoi( str );
        if( N == 0 ) {
            throw std::runtime_error( "null value of package length in configFile" );
        }

    } else if( pole == 'k' ) {
        this->k = std::stoi( str );
        if( k == 0 ) {
            throw std::runtime_error( "null value of quantity of strings in configFile" );
        }
    }

}


void DataGenerator::writeToFile( const std::string& path ) {

    srand( time( NULL ) );

    std::ofstream file( path );

    for( uint32_t numOfStr = 0; numOfStr < this->k; numOfStr++ ) {

        uint32_t l = 1 + rand() % ( rmax_len * N ); // set current length of line

        for( uint32_t length = 0; length < l; length++ ) {
            sym = makeSym(); // make random symbol
            file << sym;
            // std::cerr << sym;

        }
// if( numOfStr != this->k - 1 ) {
// file << "\n";

// }
// if( numOfStr == this->k - 1 ) {
// file << "%";

// }
    }

}

char DataGenerator::makeSym() {

    // srand( time( NULL ) );
    char intsym = 33 + rand() % ( 93 );
    if( intsym == '&' ) {
        intsym = makeSym();
    }
    return ( intsym );
}

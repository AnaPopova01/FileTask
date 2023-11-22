#include "dataRead.h"

// Standart - добавляет подзаголовок к данным и выравнивает пакет до фиксированной длины, заголовок состоит только из порядкового номера пакета
// Magic - добавляет подзаголовок к данным,заголовок состоит ключевого слова, порядкового номера пакета и его длины

using std::cerr;

DataRead::DataRead() {

}

void DataRead::readFromFile( const string& inputfile, const string& outputfile ) {

    std::ifstream originFile( inputfile ); // open file with origin data

    if( !originFile.is_open() ) {
        throw std::runtime_error( "cant open file " );

    } else {

        outfile.open( outputfile );
        if( !outfile.is_open() ) {

            throw std::runtime_error( "cant open file " );

        } else {

            std::string str;

            while( !originFile.eof() ) { // until file finish

                std::getline( originFile, str );

                strdata.push_back( str );

            }
            getProtInfo();
            divideHeadFromInfo();
            isMixed();
            if( stdProt == true ) {
                cleanData();
            }
            printData();
            outfile << "\n";
            outfile.close(); // close file
        }

    }
}

void DataRead::getProtInfo() {

    std::string str1 = strdata[ 0 ];
    std::string str2 = strdata[ 1 ];
    str1.erase( 4, str1.size() - 4 );
    str2.erase( 4, str2.size() - 4 );
    if( std::stoi( str1 ) == std::stoi( str2 ) ) {
        stdProt = false;
        headerSize = 12;

    } else {
        stdProt = true;
        headerSize = 4;
    }
}

void DataRead::divideHeadFromInfo() {

    auto size = strdata.size();
    std::string str1;
    std::string str2;
    uint16_t a = 0;
    if( stdProt == false ) {

        a = 4;
    }
    for( uint16_t i = 0; i < size; i++ ) {

        str1 = strdata[ i ];
        str2.assign( str1, 0 + a, headerSize - 2 * a );
        intdata.push_back( std::stoi( str2 ) );
        str1.erase( 0, headerSize );
        strdata[ i ] = str1;
    }
}

void DataRead::isMixed() {

    for( uint16_t i = 0; i < intdata.size(); i++ ) {

        if( intdata[ i ] != i ) {

            mixFlag = true;
            break;
        }
    }
}
void DataRead::cleanData() {

    std::string str = "";

    for( uint16_t i = 0; i < strdata.size(); i++ ) {

        str = strdata[ i ];
        auto pos = str.find( "&" );
        str.erase( pos, str.size() );
        strdata[ i ] = str;
    }
}

void DataRead::printData() {

    if( mixFlag == false ) {

        printPack();

    } else {


    }
}

void DataRead::printPack() {


    for( uint16_t nline = 0; nline < strdata.size(); nline++ ) {
        int count = 0;
// if( nline == 31 ) {
// std::cerr << "stop";
// }

        while( strdata[ nline ].size() != 0 ) {

            std::string str = strdata[ nline ].substr( 0, 3 );
            strdata[ nline ].erase( 0, 3 );
            uint16_t num = std::stoi( str );

            if( num == 0 ) {

                if( kOfPackets != 0 ) {
                    outfile << "\n";
                }
                kOfPackets++;
            }

            outfile << strdata[ nline ][ 0 ];
            count++;
            strdata[ nline ].erase( 0, 1 );

        }

        // cerr << nline << ") " << count << "\n";
    }
}


// open file
// read first two strings
// if first 4 symbols is 3565 then it is mag-protocol, else it is std-protocol
// divide header and info into 2 vectors of int and strings. If Std then take 4 sym, if Mag take 12 sym
// if Mag then clean headers to idOfPack.
// If first 5 of packets written in order,then noMix, else mix
// in both ways we in final get vector of int and vector of string.
// if Std clean info from &-sym

// If noMix then print, else find iter using vec of int for nextPacket and use it to took from vec os string the one which is nessesary


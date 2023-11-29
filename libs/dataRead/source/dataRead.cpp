#include "dataRead/dataRead.h"

// Standart - добавляет подзаголовок к данным и выравнивает пакет до фиксированной длины, заголовок состоит только из порядкового номера пакета
// Magic - не добавляет подзаголовок к данным,заголовок состоит ключевого слова, порядкового номера пакета и его длины

using std::cerr;


void DataRead::readFromFile( const string& inputfile, const string& outputfile ) {

    std::ifstream originFile( inputfile, std::ios::binary ); // open file with origin data

    if( !originFile.is_open() ) {
        throw std::runtime_error( "cant open INPUT file " );

    } else {

        outfile.open( outputfile, std::ios::binary );
        if( !outfile.is_open() ) {

            throw std::runtime_error( "cant open OUTPUT file " );

        } else {

            char value;
            int count = 0;

            while( !originFile.eof() ) {

                originFile.read( ( char* )&value, sizeof( char ) );

                if( data.size() > 2530 ) {

                    if( value == '&' ) {
                        count++;
                    }
                }

                data += value;
            }
            // std::cerr << "count is = " << count << "\n";
            getProtInfo();
            divideHeadFromInfo();

            printData();

            outfile.close(); // close file
        }

    }
}

void DataRead::getProtInfo() {

    std::string str = data.substr( 0, 4 );

    if( std::stoi( str ) == keyword ) {
        stdProt = false;
        headerSize = 12;

    } else {
        stdProt = true;
        headerSize = 4;
    }
}

void DataRead::divideHeadFromInfo() {

    // есть одна большая строка данных, в зависимости от вида протокола разделяем хедер и данные и записываем их в map
    // если Стд: берем первые 50, из них первые 4 вырезаем и ту инт и добавляем их в качестве ключа, а остаток строки в вэлью мап, и так пока размер строки не равен нулю
    // если Маг: стираем кей-хедер, копируем от начала до следующего кей-хедера, первые 4 ту инт и в ключ, стираем сайз а остальное в вэлью мап, и так до размера даты ==0

    if( stdProt == true ) {

        while( data.size() != 1 ) {

            std::string str = data.substr( 0, 50 );
            // std::cerr << str << "\n";
            std::string cleandata;
            data.erase( 0, 50 );
            uint16_t id = stoi( str.substr( 0, headerSize ) );
            str.erase( 0, headerSize );
            for( uint16_t i = 0; i <  str.size() / ( k_in_data + 1 ); i++ ) {


                cleandata += str[ i * ( k_in_data + 1 ) + k_in_data ];
            }
            auto pos = cleandata.find( "&" );
            if( pos != std::string::npos ) {
                cleandata.erase( pos, cleandata.size() - pos );
            }
            strdata.emplace( id, cleandata );
        }


    } else if( stdProt == false ) {

        while( data.size() != 1 ) {
            std::string keyW = data.substr( 0, std::to_string( keyword ).size() );
            if( keyW != std::to_string( keyword ) ) {

                std::cerr << "in divideHeadFromInfo using Magic protocol smth wrong";
            }
            data.erase( 0, std::to_string( keyword ).size() );

            uint16_t id = stoi( data.substr( 0, k_in_1stHead ) );
            uint16_t length = stoi( data.substr( k_in_1stHead, k_in_2ndHead ) );
            data.erase( 0,  k_in_1stHead + k_in_2ndHead );
            std::string str = data.substr( 0, length );
            strdata.emplace( id, str );
            data.erase( 0, length );


        }
    }

}
// auto size = strdata.size();
// std::string str1;
// std::string str2;
// uint16_t a = 0;
// if( stdProt == false ) {

// a = 4;
// }
// for( uint16_t i = 0; i < size; i++ ) {

// str1 = strdata[ i ];
// str2.assign( str1, 0 + a, headerSize - 2 * a );
//// intdata.push_back( std::stoi( str2 ) );
// str1.erase( 0, headerSize );
// strdata[ i ] = str1;
// }


/*
   void DataRead::isMixed() {

    for( uint16_t i = 0; i < intdata.size(); i++ ) {

        if( intdata[ i ] != i ) {

            mixFlag = true;
            break;
        }
    }
   }
 */

// void DataRead::cleanData() {

// std::string str = "";

// for( uint16_t i = 0; i < strdata.size(); i++ ) {

// str = strdata[ i ];
// auto pos = str.find( "&" );
// str.erase( pos, str.size() );
// strdata[ i ] = str;
// }
// }

void DataRead::printData() {

    if( mixFlag == false ) {

        for( const auto& [ key, value ] : strdata ) {
            // std::cout << key << ": " << value << std::endl;
            outfile << value;
        }

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


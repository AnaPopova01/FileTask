#include "dataRead/dataRead.h"

// Standart - добавляет подзаголовок к данным и выравнивает пакет до фиксированной длины, заголовок состоит только из порядкового номера пакета
// Magic - не добавляет подзаголовок к данным,заголовок состоит ключевого слова, порядкового номера пакета и его длины

using std::cerr;


void DataRead::readProcessing( const string& inputfile, const string& outputfile ) {

    std::ifstream originFile( inputfile, std::ios::binary ); // open file with origin data

    if( !originFile.is_open() ) {
        throw std::runtime_error( "cant open input reader file" );

    } else {

        outfile.open( outputfile, std::ios::binary );
        if( !outfile.is_open() ) {

            throw std::runtime_error( "cant open output reader file" );

        } else {

            char value;
            int count = 0;

            while( !originFile.eof() ) {

                originFile.read( ( char* )&value, sizeof( char ) );

// if( data.size() > 2530 ) {

// if( value == '&' ) {
// count++;
// }
// }

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

    std::string str = data.substr( 0, std::to_string( keyword ).size() );

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
    // если Стд: берем первые N, из них первые 4 вырезаем и ту инт и добавляем их в качестве ключа, а остаток строки в map.value , и так пока размер строки не равен нулю
    // если Маг: стираем keyword, копируем от начала до следующего keyword, первые 4 ту инт и в ключ, стираем сайз а остальное в map.value, и так до data.size ==0

    if( stdProt == true ) {

        while( data.size() != 1 ) {

            std::string str = data.substr( 0, N );
            // std::cerr << str << "\n";
            std::string cleandata;
            data.erase( 0, N );
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




void DataRead::printData() {

    for( const auto& [ key, value ] : strdata ) {
        // std::cout << key << ": " << value << std::endl;
        outfile << value;
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


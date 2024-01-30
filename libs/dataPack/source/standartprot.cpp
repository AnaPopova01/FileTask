#include "standartprot.h"


// std::mutex mute;
std::mutex mtx;

void StandartProt::setProtocol( Protocol& protocol ) {

    this->prot = protocol;

    headerSize = this->k_in_1stHead;

    this->maxSpace = prot.N - headerSize;

    resetPackSpace();
}
// here lays working multithreading version of writeToFile
/*
   void StandartProt::writeToFile( const std::string& outputfile ) {

    this->outfile.open( outputfile, std::ios::binary ); // open file to write
    if( !outfile.is_open() ) {

        throw std::runtime_error( "cant open output packer file " );

    } else {

        if( ( type == PackerType::Aligned ) && ( prot.mixPackets == false ) ) {

            auto packetCount = getPacketsCount(); // количество пакетов на которые можно разделить данные
            int symCount = 0;

            data = addServiceInfo( data, 0 );
            alignData();

            auto makingOnePacket { [ & ] ( const uint16_t j ) {

                               std::string subStr;
                               {

                                   std::lock_guard< std::mutex > guard( mtx );
                                   // std::cerr << j << "st hell starts " << "\n";
                                   // std::cerr << j << "subStr before OnePacked was =" << subStr << "\n";

                               }

                               subStr = createOnePacket( j );

                               {
                                   std::lock_guard< std::mutex > guard( mtx );
                                   // std::cerr << j << "st subStr after OnePacked is =" << subStr << "\n";
                                   strdata.emplace( j, subStr );
                                   // std::cerr << j << "which version was emplaced =" << subStr << "\n";
                               }

                           }
            };

            for( uint16_t i = 0; i < packetCount; i++ ) {

                // std::cerr << i << "st thread start working " << "\n";
                threads.emplace_back( makingOnePacket, i );

            }

            for( uint16_t i = 0; i < packetCount; i++ ) {
                threads[ i ].join();


            }
            printData();

        } else {

            addInfo();// добавляем служебную информацию
            formPack();
            printvecdata();
        }
        outfile.close();
    }

   }
 */

void StandartProt::writeToFile( const std::string& outputfile ) {

    this->outfile.open( outputfile, std::ios::binary ); // open file to write
    if( !outfile.is_open() ) {

        throw std::runtime_error( "cant open output packer file " );

    } else {

        if( ( type == PackerType::Aligned ) && ( prot.mixPackets == false ) ) {

            auto packetCount = getPacketsCount(); // количество пакетов на которые можно разделить данные
            auto length = getSubstrLen();
            data = addServiceInfo( data );
            alignData();
            auto freeSpaceInPack = spaceInPack;
            uint8_t amountOfSymIn1Header = k_in_1stHead;

            vector< std::promise< string > > promiseVec;
            vector< std::future< string > > futureVec;
            promiseVec.reserve( packetCount );
            futureVec.reserve( packetCount );
            for( int var = 0; var < packetCount; ++var ) {

                futureVec[ var ] = promiseVec[ var ].get_future();
            }

            // string subStr;
            // uint16_t i = 0;
            // auto subStr = data.substr(  0  * length, length );

// auto taskBind = std::bind( makeOnePack, 0,  subStr, freeSpaceInPack, amountOfSymIn1Header );

// auto returnOnePack { [  ] ( string subStr, uint16_t i ) {
// subStr = taskBind();
// promiseVec[ i ].set_value( subStr );
// }
// };


// std::cerr << "subStr before " << subStr << "\n";
// returnOnePack();
// std::cerr << "subStr after " << futureStr.get() << "\n";


            uint16_t poolCounter = 1;
            ThreadPool pool( poolCounter );

            for( uint16_t i = 0; i < packetCount; i++ ) {

// auto subStr = data.substr(  i  * length, length );
// auto taskBind = std::bind( makeOnePack, i, subStr, freeSpaceInPack, amountOfSymIn1Header );
// pool.addTask(  returnOnePack( subStr, i ) );

// std::cerr << "\t" << i << "st task " << "added \n";
// {
// std::lock_guard< std::mutex > guard( mtx );
// std::cerr << j << "st subStr after OnePacked is =" << subStr << "\n";
// strdata.emplace( j, subStr );
// std::cerr << j << "which version was emplaced =" << subStr << "\n";
// }

            }
            // collectResults(){for (in range){emplace (futureData.i,future)}};
            pool.stop();
            printData();

        } else {

            addInfo();// добавляем служебную информацию
            formPack();
            printvecdata();
        }
        outfile.close();
    }

}



string StandartProt::makeOnePack( const uint16_t j, string subStr, uint16_t freeSpaceInPack, uint8_t amountOfSymIn1Header ) {

// {
// std::lock_guard< std::mutex > guard( mtx );
// std::cerr << j << " st hell starts " << "\n";
// std::cerr << j << "subStr before OnePacked was =" << subStr << "\n";
// }

    while( subStr.size() < freeSpaceInPack ) {
        subStr = subStr + "&";
    }

    std::string header1 = std::to_string( j );
    while( header1.size() != amountOfSymIn1Header ) {
        header1 = "0" + header1;
    }
    subStr = header1 + subStr;
/*
   {
   std::lock_guard< std::mutex > guard( mtx );
   std::cerr << j << " st hell stop " << "\n";
   std::cerr << j << "subStr after OnePacked  =" << subStr << "\n";

   }*/

    return subStr;


}

// void StandartProt::connectVec( int packetCount ) {

// promiseVec.reserve( packetCount );
// futureVec.reserve( packetCount );
// for( int var = 0; var < packetCount; ++var ) {

// futureVec[ var ] = promiseVec[ var ].get_future();
// }

// }


// {
// std::lock_guard< std::mutex > guard( mtx );
// std::cerr << j << "st subStr after OnePacked is =" << subStr << "\n";
// strdata.emplace( j, subStr );
// std::cerr << j << "which version was emplaced =" << subStr << "\n";
// }


void StandartProt::finishPack( std::string& str ) { // also add pack to common vector

    while( str.size() < maxSpace ) {
        str = str + "&";
    }

    addHeadInfo( str );
    vecdata.push_back( str );
}

void StandartProt::addInfo() {

    std::string payloadheader;
    uint16_t endOfStr = data.size();

    for( uint16_t i = 0; i < endOfStr; i++ ) {

        payloadheader = std::to_string( i );
        while( payloadheader.size() < this->serviceDataFieldLen ) {
            payloadheader = "0" + payloadheader;
        }
        data.insert( i * ( serviceDataFieldLen + 1 ), payloadheader );
    }
}


void StandartProt::addHeadInfo( std::string& str ) {

    std::string header1 = std::to_string( currpackNum );
    while( header1.size() != k_in_1stHead ) {
        header1 = "0" + header1;
    }
    str = header1 + str;
    // outfile << header1 << "\t";

}

// std::string StandartProt::createOnePacket( uint16_t i,uint16_t length ) {
//// std::cerr << "before addServiceInfo is " << subStr << "\n";
// }


uint16_t StandartProt::getSubstrLen() {

    return ( serviceDataFieldLen + 1 ) * trunc( spaceInPack / ( serviceDataFieldLen + 1 ) );
}


std::string StandartProt::addServiceInfo( std::string subStr ) {

    int symCount = 0;
    std::string payloadheader;
    uint16_t endOfStr = subStr.size();

    for( uint16_t i = 0; i < endOfStr; i++ ) {

        payloadheader = std::to_string( symCount );
        while( payloadheader.size() < this->serviceDataFieldLen ) {
            payloadheader = "0" + payloadheader;
        }
        subStr.insert( i * ( serviceDataFieldLen + 1 ), payloadheader );
        symCount++;
    }
    return subStr;
}

void StandartProt::alignData() {
    int packetCount = ceil( data.size() / ( ( serviceDataFieldLen + 1 ) * trunc( maxSpace / ( serviceDataFieldLen + 1 ) ) ) );

    while( data.size() <  packetCount * maxSpace ) {
        data = data + "&";
    }


}

int StandartProt::getPacketsCount() {

    int amountOfPackets = ceil( data.size() / trunc( maxSpace / ( ( serviceDataFieldLen + 1 ) ) ) );
    // int amountOfPackets = ceil( data.size() / ( ( serviceDataFieldLen + 1 ) * trunc( spaceInPack / ( serviceDataFieldLen + 1 ) ) ) ); // количество пакетов для упаковки всех данных
    if( amountOfPackets == 0 ) {
        amountOfPackets++; // должен быть как минимум один пакет
    }
    return amountOfPackets;
}

std::string StandartProt::toFinishPack( std::string subStr, uint16_t i, uint16_t spaceInPack, uint8_t k_in_1stHead ) {

    while( subStr.size() < spaceInPack ) {
        subStr = subStr + "&";
    }

    std::string header1 = std::to_string( i );
    while( header1.size() != k_in_1stHead ) {
        header1 = "0" + header1;
    }
    subStr = header1 + subStr;
    return subStr;
}


void StandartProt::printData() {

    for( const auto& [ key, value ] : strdata ) {
        std::cerr << key << ": " << value << std::endl;
        outfile << value;
    }
}


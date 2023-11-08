#include <gtest/gtest.h>
#include "src/dataPack.h"
#include "src/randPack.h"
#include "include/packerfactory.h"

// TEST( PackerTests, creating ) {

// auto tatus = createPackerImpl();
//// tatus->writeToFile();
// }

TEST( PackerTests, AlignedtWriteNoMix ) {

    auto tatus = createPackerImpl( PackerType::Aligned );
    Protocol prot { ProtocolType::Standart,  50, 0 };

    const string inputfile = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/bin/originCode.txt";
    const string outputfile = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/bin/aligned_NO_mix.txt";
    tatus->writeToFile( inputfile, outputfile, prot );

    std::ifstream originFile( outputfile ); // open file with origin strings

    if( !originFile.is_open() ) {

        throw std::runtime_error( "cant open file " );

    } else {


        std::string str;

        while( !originFile.eof() ) {

            std::getline( originFile, str );

            auto siz = str.size();
            ASSERT_EQ( siz, 50 );

        }

    }



}

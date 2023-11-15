#include <gtest/gtest.h>
#include "src/dataPack.h"
#include "src/randPack.h"
#include "include/packerfactory.h"

TEST( PackerTests, creating ) {

    auto tatus = createPackerImpl();
    tatus->writeToFile();
}



TEST( PackerTests, AlignedtWriteStd ) {

    auto tatus = createPackerImpl( PackerType::Aligned );
    Protocol prot { ProtocolType::Standart,  50, 0 };

    const string inputfile = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/bin/originCode2.txt";
    const string outputfile = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/bin/no_mix/aligned_Std.txt";
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

TEST( PackerTests, AlignedtWriteMagic ) {

    auto tatus = createPackerImpl( PackerType::Aligned );
    Protocol prot { ProtocolType::Magic,  50, 0 };
    // tatus->getKey();

    const string inputfile = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/bin/originCode2.txt";
    const string outputfile = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/bin/no_mix/aligned_Mag.txt";
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

TEST( PackerTests, RandomtWriteStd ) {

    auto tatus = createPackerImpl( PackerType::Random );
    Protocol prot { ProtocolType::Standart,  50, 0 };

    const string inputfile = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/bin/originCode2.txt";
    const string outputfile = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/bin/no_mix/random_Std.txt";
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
            // ASSERT_GT( siz, 50 );

        }

    }
}

TEST( PackerTests, RandomtWriteMagic ) {

    auto tatus = createPackerImpl( PackerType::Random );
    Protocol prot { ProtocolType::Magic,  50, 0 };

    const string inputfile = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/bin/originCode2.txt";
    const string outputfile = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/bin/no_mix/random_Mag.txt";
    tatus->writeToFile( inputfile, outputfile, prot );
    std::ifstream originFile( outputfile ); // open file with origin strings

    if( !originFile.is_open() ) {

        throw std::runtime_error( "cant open file " );

    } else {


        std::string str;

        while( !originFile.eof() ) {

            std::getline( originFile, str );

            auto siz = str.size();
            ASSERT_LE( siz, 50 );
            ASSERT_GE( siz, 16 );
        }

    }
}




TEST( PackerTests, AlignedtWriteStd_MIX ) {

    auto tatus = createPackerImpl( PackerType::Aligned );
    Protocol prot { ProtocolType::Standart,  50, 1 };
    // tatus->getKey();

    const string inputfile = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/bin/originCode2.txt";
    const string outputfile = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/bin/mix/aligned_Std_MIX.txt";
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

TEST( PackerTests, AlignedtWriteMag_MIX ) {

    auto tatus = createPackerImpl( PackerType::Aligned );
    Protocol prot { ProtocolType::Magic,  50, 1 };
    // tatus->getKey();

    const string inputfile = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/bin/originCode2.txt";
    const string outputfile = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/bin/mix/aligned_Mag_MIX.txt";
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


TEST( PackerTests, RandomtWriteStd_MIX ) {

    auto tatus = createPackerImpl( PackerType::Random );
    Protocol prot { ProtocolType::Standart,  50, 1 };

    const string inputfile = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/bin/originCode2.txt";
    const string outputfile = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/bin/mix/random_Std_MIX.txt";
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

TEST( PackerTests, RandomtWriteMagic_MIX ) {

    auto tatus = createPackerImpl( PackerType::Random );
    Protocol prot { ProtocolType::Magic,  50, 1 };

    const string inputfile = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/bin/originCode2.txt";
    const string outputfile = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/bin/mix/random_Mag_MIX.txt";
    tatus->writeToFile( inputfile, outputfile, prot );
    std::ifstream originFile( outputfile ); // open file with origin strings

    if( !originFile.is_open() ) {

        throw std::runtime_error( "cant open file " );

    } else {


        std::string str;

        while( !originFile.eof() ) {

            std::getline( originFile, str );

            auto siz = str.size();
            ASSERT_LE( siz, 50 );
            ASSERT_GE( siz, 16 );

        }

    }
}

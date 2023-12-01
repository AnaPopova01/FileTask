#include <gtest/gtest.h>
#include "dataPack/packerfactory.h"
using std::string;


// TEST( PackerTests, creating ) {

// auto tatus = createPackerImpl();
// tatus->writeToFile();
// }



TEST( PackerTests, Aligned_Std ) {

    auto tatus = createPackerImpl( PackerType::Aligned );
    Protocol prot { ProtocolType::Standart,  50, 0 };

    const string inputfile = "packer/randsym.txt";
    const string outputfile = "packer/aligned/Std.txt";
    tatus->pack_processing( inputfile, outputfile, prot );


    std::ifstream fromPacker( outputfile, std::ios::binary );

    if( !fromPacker.is_open() ) {

        throw std::runtime_error( "cant open file for testing" );

    } else {

        char value;
        int count = 0;

        while( !fromPacker.eof() ) {

            fromPacker.read( ( char* )&value, sizeof( char ) );
            count++;

        }

        ASSERT_EQ( count - 1, 135 * 50 );
    }


}

TEST( PackerTests, Aligned_Magic ) {

    auto tatus = createPackerImpl( PackerType::Aligned );
    Protocol prot { ProtocolType::Magic,  50, 0 };

    const string inputfile = "packer/randsym.txt";
    const string outputfile = "packer/aligned/Mag.txt";
    tatus->pack_processing( inputfile, outputfile, prot );

    std::ifstream fromPacker( outputfile, std::ios::binary );

    if( !fromPacker.is_open() ) {

        throw std::runtime_error( "cant open file " );

    } else {

        char value;
        int count = 0;

        while( !fromPacker.eof() ) {

            fromPacker.read( ( char* )&value, sizeof( char ) );
            count++;

        }

        ASSERT_EQ( count - 1, 1595 );
    }



}

TEST( PackerTests, Aligned_Std_MIX ) {

    auto tatus = createPackerImpl( PackerType::Aligned );
    Protocol prot { ProtocolType::Standart,  50, 1 };

    const string inputfile = "packer/randsym.txt";
    const string outputfile = "packer/aligned/Std_MIX.txt";
    tatus->pack_processing( inputfile, outputfile, prot );

    std::ifstream fromPacker( outputfile, std::ios::binary );

    if( !fromPacker.is_open() ) {

        throw std::runtime_error( "cant open file " );

    } else {

        char value;
        std::string str;
        int count = 0;

        while( !fromPacker.eof() ) {

            fromPacker.read( ( char* )&value, sizeof( char ) );
            if( count < 4 ) {
                str += value;
            }
            count++;
        }

        ASSERT_NE( str, "0000" );
        ASSERT_EQ( count - 1, 135 * 50 );
    }


}

TEST( PackerTests, Aligned_Mag_MIX ) {

    auto tatus = createPackerImpl( PackerType::Aligned );
    Protocol prot { ProtocolType::Magic,  50, 1 };

    const string inputfile = "packer/randsym.txt";
    const string outputfile = "packer/aligned/Mag_MIX.txt";
    tatus->pack_processing( inputfile, outputfile, prot );

    int kOfLines = 0;
    std::ifstream fromPacker( outputfile, std::ios::binary );

    if( !fromPacker.is_open() ) {

        throw std::runtime_error( "cant open file " );

    } else {

        char value;
        std::string str;
        int count = 0;

        while( !fromPacker.eof() ) {

            fromPacker.read( ( char* )&value, sizeof( char ) );
            if( ( count >= 4 ) & ( str.size() != 4 ) ) {
                str += value;
            }
            count++;
        }

        ASSERT_NE( str, "0000" );
        ASSERT_EQ( count - 1, 1595 );
    }


}

TEST( PackerTests, Random_Std ) {

    auto tatus = createPackerImpl( PackerType::Random );
    Protocol prot { ProtocolType::Standart,  50, 0 };

    const string inputfile = "packer/randsym.txt";
    const string outputfile = "packer/random/Std.txt";
    tatus->pack_processing( inputfile, outputfile, prot );

    std::ifstream fromPacker( outputfile, std::ios::binary );

    if( !fromPacker.is_open() ) {

        throw std::runtime_error( "cant open file " );

    } else {

        char value;
        int count = 0;

        while( !fromPacker.eof() ) {

            fromPacker.read( ( char* )&value, sizeof( char ) );
            count++;

        }

        ASSERT_GT( count - 1, 1211 );
    }
}

TEST( PackerTests, Random_Magic ) {

    auto tatus = createPackerImpl( PackerType::Random );
    Protocol prot { ProtocolType::Magic,  50, 0 };

    const string inputfile = "packer/randsym.txt";
    const string outputfile = "packer/random/Mag.txt";
    tatus->pack_processing( inputfile, outputfile, prot );

    std::ifstream fromPacker( outputfile, std::ios::binary );

    if( !fromPacker.is_open() ) {

        throw std::runtime_error( "cant open file " );

    } else {

        char value;
        int count = 0;

        while( !fromPacker.eof() ) {

            fromPacker.read( ( char* )&value, sizeof( char ) );
            count++;

        }

        ASSERT_GT( count - 1, 1211 );
    }
}

TEST( PackerTests, Random_Std_MIX ) {

    auto tatus = createPackerImpl( PackerType::Random );
    Protocol prot { ProtocolType::Standart,  50, 1 };

    const string inputfile = "packer/randsym.txt";
    const string outputfile = "packer/random/Std_MIX.txt";
    tatus->pack_processing( inputfile, outputfile, prot );

    std::ifstream fromPacker( outputfile, std::ios::binary );

    if( !fromPacker.is_open() ) {

        throw std::runtime_error( "cant open file " );

    } else {

        char value;
        std::string str;
        int count = 0;

        while( !fromPacker.eof() ) {

            fromPacker.read( ( char* )&value, sizeof( char ) );
            if( ( count < 4 ) & ( str.size() < 4 ) ) {
                str += value;
            }
            count++;
        }

        ASSERT_NE( str, "0000" );

        ASSERT_GT( count - 1, 1211 );
    }
}

TEST( PackerTests, Random_Mag_MIX ) {

    auto tatus = createPackerImpl( PackerType::Random );
    Protocol prot { ProtocolType::Magic,  50, 1 };

    const string inputfile = "packer/randsym.txt";
    const string outputfile = "packer/random/Mag_MIX.txt";
    tatus->pack_processing( inputfile, outputfile, prot );

    std::ifstream fromPacker( outputfile, std::ios::binary );

    if( !fromPacker.is_open() ) {

        throw std::runtime_error( "cant open file " );

    } else {

        char value;
        std::string str;
        int count = 0;

        while( !fromPacker.eof() ) {

            fromPacker.read( ( char* )&value, sizeof( char ) );
            if( ( count >= 4 ) & ( str.size() != 4 ) ) {
                str += value;
            }
            count++;
        }
        ASSERT_NE( str, "0000" );
        ASSERT_GT( count - 1, 1211 );
    }
}



/*
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

 */



// TEST( PackerTests, RandomsstWriteMagic_MIX ) {

// std::vector nums = { 5, 34, 2, 4, 60, 8, 3, 209, 599 };

// std::set< decltype( nums )::value_type > sorted( nums.begin(), nums.end() );



// for( auto vVal : nums ) {
// std::cerr << vVal << ", ";
// }
// std::cerr <<  "\n ";

// for( auto sval : sorted ) {
// std::cerr << sval << ", ";
// }
// std::cerr <<  "\n ";

// }



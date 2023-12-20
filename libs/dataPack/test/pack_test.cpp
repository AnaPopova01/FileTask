#include <gtest/gtest.h>
#include "dataPack/packerfactory.h"
// #include "libs/dataRead/include/dataRead/dataRead.h"

using std::string;


TEST( PackerTests, packer_creatingWrongType_runtimeError ) {

    PackerType type{ 2 };
    try {
        auto tatus = createPackerImpl( type, ProtocolType::Standart );
    } catch( std::runtime_error& e ) {

        ASSERT_STREQ( e.what(),  " unsupported packer type " );

    }

}

TEST( PackerTests, bothType_wrongInputPath_runtimeError ) {
    try {
        auto tatus = createPackerImpl( PackerType::Aligned, ProtocolType::Standart );
        Protocol prot {  50, 0 };

        const string inputfile = "samuraiway.noAim";
        const string outputfile = "packer/aligned/Std.txt";
        tatus->packProcessing( inputfile, outputfile, prot );

    } catch( std::runtime_error& e ) {

        ASSERT_STREQ( e.what(),  "cant open input packer file" );

    }

}

// TEST( PackerTests, sizeOfPacket ) {
// try {
// auto tatus = createPackerImpl( PackerType::Aligned );
// Protocol prot { ProtocolType::Standart,  0, 0 };

// const string inputfile = "samuraiway.noAim";
// const string outputfile = "packer/aligned/Std.txt";
// tatus->packProcessing( inputfile, outputfile, prot );

// } catch( std::runtime_error& e ) {

// ASSERT_STREQ( e.what(),  "cant input packer file" );

// }

// }

TEST( PackerTests, alignedType_StandartProt_CorrectValues ) {

    std::map< std::uint8_t, string > files;
    files[ 0 ] = "twenty_enter";
    files[ 1 ] = "empty";
    files[ 2 ] = "one_sym";
    files[ 3 ] = "rand_lines";
    files[ 4 ] = "rand_sym";

    for( const auto& cases : files ) {

        std::cerr << "case = " << cases.second << endl;
        auto tatus = createPackerImpl( PackerType::Aligned, ProtocolType::Standart );
        Protocol prot {   50, 0 };
        const string inputfile = "packer/bin/toPack/" + cases.second + ".txt";

        const string outputfile = "packer/bin/toRead/packed/aligned/" + cases.second + "/Std.txt";
        tatus->packProcessing( inputfile, outputfile, prot );


        const string idealPath = "packer/bin/toRead/ideal_packed/aligned/" + cases.second + "/Std.txt";

        std::ifstream fromPacker( outputfile, std::ios::binary );
        std::ifstream idealPack( idealPath, std::ios::binary );

        if( ( !fromPacker.is_open() ) || ( !idealPack.is_open() ) ) {

            throw std::runtime_error( "cant open files for testing Packer" );

        } else {


            std::string ideal_str;
            std::string test_str;

            while( !idealPack.eof() ) {

                std::getline( idealPack, ideal_str );
                std::getline( fromPacker, test_str );

                ASSERT_EQ( ideal_str, test_str );


            }

        }
    }

}

TEST( PackerTests, alignedType_MagicProt_CorrectValues ) {

    std::map< std::uint8_t, string > files;
    files[ 0 ] = "twenty_enter";
    files[ 1 ] = "empty";
    files[ 2 ] = "one_sym";
    files[ 3 ] = "rand_lines";
    files[ 4 ] = "rand_sym";

    for( const auto& cases : files ) {

        auto tatus = createPackerImpl( PackerType::Aligned, ProtocolType::Magic );
        Protocol prot { 50, 0 };
        const string inputfile = "packer/bin/toPack/" + cases.second + ".txt";

        const string outputfile = "packer/bin/toRead/packed/aligned/" + cases.second + "/Mag.txt";
        tatus->packProcessing( inputfile, outputfile, prot );

        const string idealPath = "packer/bin/toRead/ideal_packed/aligned/" + cases.second + "/Mag.txt";

        std::ifstream fromPacker( outputfile, std::ios::binary );
        std::ifstream idealPack( idealPath, std::ios::binary );

        if( ( !fromPacker.is_open() ) || ( !idealPack.is_open() ) ) {

            throw std::runtime_error( "cant open files for testing Packer" );

        } else {


            std::string ideal_str;
            std::string test_str;

            while( !idealPack.eof() ) {

                std::getline( idealPack, ideal_str );
                std::getline( fromPacker, test_str );

                ASSERT_EQ( ideal_str, test_str );


            }

        }
    }
}

TEST( PackerTests, alignedType_StandartProtMIX_CorrectValues ) {


    std::map< std::uint8_t, string > files;
    files[ 0 ] = "twenty_enter";
    files[ 1 ] = "empty";
    files[ 2 ] = "one_sym";
    files[ 3 ] = "rand_lines";
    files[ 4 ] = "rand_sym";

    for( const auto& cases : files ) {

        // std::cerr << "case = " << cases.second << endl;
        auto tatus = createPackerImpl( PackerType::Aligned, ProtocolType::Standart );
        Protocol prot {  50, 1 };
        const string inputfile = "packer/bin/toPack/" + cases.second + ".txt";

        const string outputfile = "packer/bin/toRead/packed/aligned/" + cases.second + "/Std_MIX.txt";
        tatus->packProcessing( inputfile, outputfile, prot );

        const string idealPath = "packer/bin/toRead/ideal_packed/aligned/" + cases.second + "/Std_MIX.txt";

        std::ifstream fromPacker( outputfile, std::ios::binary );
        std::ifstream idealPack( idealPath, std::ios::binary );

        if( ( !fromPacker.is_open() ) || ( !idealPack.is_open() ) ) {

            throw std::runtime_error( "cant open files for testing Packer" );

        } else {


            std::string ideal_str;
            std::string test_str;

            while( !idealPack.eof() ) {

                std::getline( idealPack, ideal_str );
                std::getline( fromPacker, test_str );

                ASSERT_EQ( ideal_str, test_str );


            }

        }
    }


}

TEST( PackerTests, alignedType_MagicProtMIX_CorrectValues  ) {

    std::map< std::uint8_t, string > files;
    files[ 0 ] = "twenty_enter";
    files[ 1 ] = "empty";
    files[ 2 ] = "one_sym";
    files[ 3 ] = "rand_lines";
    files[ 4 ] = "rand_sym";

    for( const auto& cases : files ) {

        auto tatus = createPackerImpl( PackerType::Aligned, ProtocolType::Magic );
        Protocol prot {  50, 1 };
        const string inputfile = "packer/bin/toPack/" + cases.second + ".txt";

        const string outputfile = "packer/bin/toRead/packed/aligned/" + cases.second + "/Mag_MIX.txt";
        tatus->packProcessing( inputfile, outputfile, prot );

        const string idealPath = "packer/bin/toRead/ideal_packed/aligned/" + cases.second + "/Mag_MIX.txt";

        std::ifstream fromPacker( outputfile, std::ios::binary );
        std::ifstream idealPack( idealPath, std::ios::binary );

        if( ( !fromPacker.is_open() ) || ( !idealPack.is_open() ) ) {

            throw std::runtime_error( "cant open files for testing Packer" );

        } else {


            std::string ideal_str;
            std::string test_str;

            while( !idealPack.eof() ) {

                std::getline( idealPack, ideal_str );
                std::getline( fromPacker, test_str );

                ASSERT_EQ( ideal_str, test_str );


            }

        }
    }

}

TEST( PackerTests, randomType_StandartProt_CorrectValues ) {

    std::map< std::uint8_t, string > files;
    files[ 0 ] = "twenty_enter";
    files[ 1 ] = "empty";
    files[ 2 ] = "one_sym";
    files[ 3 ] = "rand_lines";
    files[ 4 ] = "rand_sym";

    for( const auto& cases : files ) {

        auto tatus = createPackerImpl( PackerType::Random, ProtocolType::Standart );
        Protocol prot {  50, 0 };
        const string inputfile = "packer/bin/toPack/" + cases.second + ".txt";

        const string outputfile = "packer/bin/toRead/packed/random/" + cases.second + "/Std.txt";
        tatus->packProcessing( inputfile, outputfile, prot );

        const string idealPath = "packer/bin/toRead/ideal_packed/random/" + cases.second + "/Std.txt";

        std::ifstream fromPacker( outputfile, std::ios::binary );
        std::ifstream idealPack( idealPath, std::ios::binary );

        if( ( !fromPacker.is_open() ) || ( !idealPack.is_open() ) ) {

            throw std::runtime_error( "cant open files for testing Packer" );

        } else {


            std::string ideal_str;
            std::string test_str;

            while( !idealPack.eof() ) {

                std::getline( idealPack, ideal_str );
                std::getline( fromPacker, test_str );

                ASSERT_EQ( ideal_str, test_str );


            }

        }
    }
}

TEST( PackerTests, randomType_MagicProt_CorrectValues ) {

    std::map< std::uint8_t, string > files;
    files[ 0 ] = "twenty_enter";
    files[ 1 ] = "empty";
    files[ 2 ] = "one_sym";
    files[ 3 ] = "rand_lines";
    files[ 4 ] = "rand_sym";

    for( const auto& cases : files ) {

        auto tatus = createPackerImpl( PackerType::Random, ProtocolType::Magic );
        Protocol prot { 50, 0 };
        const string inputfile = "packer/bin/toPack/" + cases.second + ".txt";

        const string outputfile = "packer/bin/toRead/packed/random/" + cases.second + "/Mag.txt";
        tatus->packProcessing( inputfile, outputfile, prot );

        const string idealPath = "packer/bin/toRead/ideal_packed/random/" + cases.second + "/Mag.txt";

        std::ifstream fromPacker( outputfile, std::ios::binary );
        std::ifstream idealPack( idealPath, std::ios::binary );

        if( ( !fromPacker.is_open() ) || ( !idealPack.is_open() ) ) {

            throw std::runtime_error( "cant open files for testing Packer" );

        } else {


            std::string ideal_str;
            std::string test_str;

            while( !idealPack.eof() ) {

                std::getline( idealPack, ideal_str );
                std::getline( fromPacker, test_str );

                ASSERT_EQ( ideal_str, test_str );


            }

        }
    }
}

TEST( PackerTests, randomType_StandartProtMIX_CorrectValues ) {

    std::map< std::uint8_t, string > files;
    files[ 0 ] = "twenty_enter";
    files[ 1 ] = "empty";
    files[ 2 ] = "one_sym";
    files[ 3 ] = "rand_lines";
    files[ 4 ] = "rand_sym";

    for( const auto& cases : files ) {

        auto tatus = createPackerImpl( PackerType::Random, ProtocolType::Standart );
        Protocol prot {   50, 1 };
        const string inputfile = "packer/bin/toPack/" + cases.second + ".txt";

        const string outputfile = "packer/bin/toRead/packed/random/" + cases.second + "/Std_MIX.txt";
        tatus->packProcessing( inputfile, outputfile, prot );

        const string idealPath = "packer/bin/toRead/ideal_packed/random/" + cases.second + "/Std_MIX.txt";

        std::ifstream fromPacker( outputfile, std::ios::binary );
        std::ifstream idealPack( idealPath, std::ios::binary );

        if( ( !fromPacker.is_open() ) || ( !idealPack.is_open() ) ) {

            throw std::runtime_error( "cant open files for testing Packer" );

        } else {


            std::string ideal_str;
            std::string test_str;

            while( !idealPack.eof() ) {

                std::getline( idealPack, ideal_str );
                std::getline( fromPacker, test_str );

                ASSERT_EQ( ideal_str, test_str );


            }

        }
    }


}

TEST( PackerTests, randomType_MagicProt_MIX_CorrectValues ) {

    std::map< std::uint8_t, string > files;
    files[ 0 ] = "twenty_enter";
    files[ 1 ] = "empty";
    files[ 2 ] = "one_sym";
    files[ 3 ] = "rand_lines";
    files[ 4 ] = "rand_sym";

    for( const auto& cases : files ) {

        auto tatus = createPackerImpl( PackerType::Random,  ProtocolType::Magic );
        Protocol prot {  50, 1 };
        const string inputfile = "packer/bin/toPack/" + cases.second + ".txt";

        const string outputfile = "packer/bin/toRead/packed/random/" + cases.second + "/Mag_MIX.txt";
        tatus->packProcessing( inputfile, outputfile, prot );

        const string idealPath = "packer/bin/toRead/ideal_packed/random/" + cases.second + "/Mag_MIX.txt";

        std::ifstream fromPacker( outputfile, std::ios::binary );
        std::ifstream idealPack( idealPath, std::ios::binary );

        if( ( !fromPacker.is_open() ) || ( !idealPack.is_open() ) ) {

            throw std::runtime_error( "cant open files for testing Packer" );

        } else {


            std::string ideal_str;
            std::string test_str;

            while( !idealPack.eof() ) {

                std::getline( idealPack, ideal_str );
                std::getline( fromPacker, test_str );

                ASSERT_EQ( ideal_str, test_str );


            }

        }
    }

}



// TEST( PackerTests, Random_Std ) {

// auto tatus = createPackerImpl( PackerType::Random );
// Protocol prot { ProtocolType::Standart,  50, 0 };

// const string inputfile = "packer/randsym.txt";
// const string outputfile = "packer/random/Std.txt";
// tatus->pack_processing( inputfile, outputfile, prot );

// std::ifstream fromPacker( outputfile, std::ios::binary );

// if( !fromPacker.is_open() ) {

// throw std::runtime_error( "cant open file " );

// } else {

// char value;
// int count = 0;

// while( !fromPacker.eof() ) {

// fromPacker.read( ( char* )&value, sizeof( char ) );
// count++;

// }

// ASSERT_GT( count - 1, 1211 );
// }
// }

// TEST( PackerTests, Random_Magic ) {

// auto tatus = createPackerImpl( PackerType::Random );
// Protocol prot { ProtocolType::Magic,  50, 0 };

// const string inputfile = "packer/randsym.txt";
// const string outputfile = "packer/random/Mag.txt";
// tatus->pack_processing( inputfile, outputfile, prot );

// std::ifstream fromPacker( outputfile, std::ios::binary );

// if( !fromPacker.is_open() ) {

// throw std::runtime_error( "cant open file " );

// } else {

// char value;
// int count = 0;

// while( !fromPacker.eof() ) {

// fromPacker.read( ( char* )&value, sizeof( char ) );
// count++;

// }

// ASSERT_GT( count - 1, 1211 );
// }
// }

// TEST( PackerTests, Random_Std_MIX ) {

// auto tatus = createPackerImpl( PackerType::Random );
// Protocol prot { ProtocolType::Standart,  50, 1 };

// const string inputfile = "packer/randsym.txt";
// const string outputfile = "packer/random/Std_MIX.txt";
// tatus->pack_processing( inputfile, outputfile, prot );

// std::ifstream fromPacker( outputfile, std::ios::binary );

// if( !fromPacker.is_open() ) {

// throw std::runtime_error( "cant open file " );

// } else {

// char value;
// std::string str;
// int count = 0;

// while( !fromPacker.eof() ) {

// fromPacker.read( ( char* )&value, sizeof( char ) );
// if( ( count < 4 ) & ( str.size() < 4 ) ) {
// str += value;
// }
// count++;
// }

// ASSERT_NE( str, "0000" );

// ASSERT_GT( count - 1, 1211 );
// }
// }

// TEST( PackerTests, Random_Mag_MIX ) {

// auto tatus = createPackerImpl( PackerType::Random );
// Protocol prot { ProtocolType::Magic,  50, 1 };

// const string inputfile = "packer/randsym.txt";
// const string outputfile = "packer/random/Mag_MIX.txt";
// tatus->pack_processing( inputfile, outputfile, prot );

// std::ifstream fromPacker( outputfile, std::ios::binary );

// if( !fromPacker.is_open() ) {

// throw std::runtime_error( "cant open file " );

// } else {

// char value;
// std::string str;
// int count = 0;

// while( !fromPacker.eof() ) {

// fromPacker.read( ( char* )&value, sizeof( char ) );
// if( ( count >= 4 ) & ( str.size() != 4 ) ) {
// str += value;
// }
// count++;
// }
// ASSERT_NE( str, "0000" );
// ASSERT_GT( count - 1, 1211 );
// }
// }



///*
// TEST( PackerTests, RandomtWriteMagic ) {

// auto tatus = createPackerImpl( PackerType::Random );
// Protocol prot { ProtocolType::Magic,  50, 0 };

// const string inputfile = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/bin/originCode2.txt";
// const string outputfile = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/bin/no_mix/random_Mag.txt";
// tatus->writeToFile( inputfile, outputfile, prot );
// std::ifstream originFile( outputfile ); // open file with origin strings

// if( !originFile.is_open() ) {

// throw std::runtime_error( "cant open file " );

// } else {


// std::string str;

// while( !originFile.eof() ) {

// std::getline( originFile, str );

// auto siz = str.size();
// ASSERT_LE( siz, 50 );
// ASSERT_GE( siz, 16 );
// }

// }
// }


// TEST( PackerTests, RandomtWriteStd_MIX ) {

// auto tatus = createPackerImpl( PackerType::Random );
// Protocol prot { ProtocolType::Standart,  50, 1 };

// const string inputfile = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/bin/originCode2.txt";
// const string outputfile = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/bin/mix/random_Std_MIX.txt";
// tatus->writeToFile( inputfile, outputfile, prot );

// std::ifstream originFile( outputfile ); // open file with origin strings

// if( !originFile.is_open() ) {

// throw std::runtime_error( "cant open file " );

// } else {


// std::string str;

// while( !originFile.eof() ) {

// std::getline( originFile, str );

// auto siz = str.size();
// ASSERT_EQ( siz, 50 );

// }

// }
// }

// TEST( PackerTests, RandomtWriteMagic_MIX ) {

// auto tatus = createPackerImpl( PackerType::Random );
// Protocol prot { ProtocolType::Magic,  50, 1 };

// const string inputfile = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/bin/originCode2.txt";
// const string outputfile = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/bin/mix/random_Mag_MIX.txt";
// tatus->writeToFile( inputfile, outputfile, prot );
// std::ifstream originFile( outputfile ); // open file with origin strings

// if( !originFile.is_open() ) {

// throw std::runtime_error( "cant open file " );

// } else {


// std::string str;

// while( !originFile.eof() ) {

// std::getline( originFile, str );

// auto siz = str.size();
// ASSERT_LE( siz, 50 );
// ASSERT_GE( siz, 16 );

// }

// }
// }

// */



//// TEST( PackerTests, RandomsstWriteMagic_MIX ) {

//// std::vector nums = { 5, 34, 2, 4, 60, 8, 3, 209, 599 };

//// std::set< decltype( nums )::value_type > sorted( nums.begin(), nums.end() );



//// for( auto vVal : nums ) {
//// std::cerr << vVal << ", ";
//// }
//// std::cerr <<  "\n ";

//// for( auto sval : sorted ) {
//// std::cerr << sval << ", ";
//// }
//// std::cerr <<  "\n ";

//// }



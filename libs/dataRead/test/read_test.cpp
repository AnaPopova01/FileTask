#include <gtest/gtest.h>
#include "dataRead/dataRead.h"


TEST( ReaderTests, reader_wrongInputPath_runtimeError ) {
    try {

        DataRead obj;
        const string inpath = "samuraiway.noAim";
        const string outpath = "reader/bin/toRead/unpacked/aligned/empty/Std.txt";

        obj.readProcessing( inpath, outpath );



    } catch( std::runtime_error& e ) {

        ASSERT_STREQ( e.what(),  "cant open input reader file" );

    }

}

TEST( ReaderTests, alignedType_StandartProt_CorrectValues ) {

    std::map< int, string > files;
    files[ 0 ] = "twenty_enter";
    files[ 1 ] = "empty";
    files[ 2 ] = "one_sym";
    files[ 3 ] = "rand_lines";
    files[ 4 ] = "rand_sym";
    for( const auto& cases : files ) {

        DataRead obj;
// std::cerr << "test\t" << cases.first << "\n";

        std::string inpath = "reader/bin/toRead/packed/aligned/" + cases.second + "/Std.txt";
        std::string outpath = "reader/bin/toRead/unpacked/aligned/" + cases.second + "/Std.txt";
        std::string origpath = "reader/bin/toPack/" + cases.second + ".txt";

        obj.readProcessing( inpath, outpath );


        std::ifstream originFile(  origpath );
        std::ifstream unpackedFile( outpath );

        if( ( !originFile.is_open() ) || ( !unpackedFile.is_open() ) ) {

            throw std::runtime_error( "cant open files for testing" );

        } else {


            std::string orig_str;
            std::string unpack_str;

            while( !originFile.eof() ) {

                std::getline( originFile, orig_str );
                std::getline( unpackedFile, unpack_str );

                ASSERT_EQ( orig_str, unpack_str );


            }

        }
    }
}

TEST( ReaderTests, alignedType_MagicProt_CorrectValues ) {

    std::map< int, string > files;
    files[ 0 ] = "twenty_enter";
    files[ 1 ] = "empty";
    files[ 2 ] = "one_sym";
    files[ 3 ] = "rand_lines";
    files[ 4 ] = "rand_sym";
    for( const auto& cases : files ) {

        DataRead obj;
// std::cerr << "test\t" << cases.first << "\n";

        std::string inpath = "reader/bin/toRead/packed/aligned/" + cases.second + "/Mag.txt";
        std::string outpath = "reader/bin/toRead/unpacked/aligned/" + cases.second + "/Mag.txt";
        std::string origpath = "reader/bin/toPack/" + cases.second + ".txt";

        obj.readProcessing( inpath, outpath );


        std::ifstream originFile(  origpath );
        std::ifstream unpackedFile( outpath );

        if( ( !originFile.is_open() ) || ( !unpackedFile.is_open() ) ) {

            throw std::runtime_error( "cant open files for testing" );

        } else {


            std::string orig_str;
            std::string unpack_str;

            while( !originFile.eof() ) {

                std::getline( originFile, orig_str );
                std::getline( unpackedFile, unpack_str );

                ASSERT_EQ( orig_str, unpack_str );


            }

        }
    }
}

TEST( ReaderTests, alignedType_StandartProtMIX_CorrectValues ) {

    std::map< int, string > files;
    files[ 0 ] = "twenty_enter";
    files[ 1 ] = "empty";
    files[ 2 ] = "one_sym";
    files[ 3 ] = "rand_lines";
    files[ 4 ] = "rand_sym";
    for( const auto& cases : files ) {

        DataRead obj;
// std::cerr << "test\t" << cases.first << "\n";

        std::string inpath = "reader/bin/toRead/packed/aligned/" + cases.second + "/Std_MIX.txt";
        std::string outpath = "reader/bin/toRead/unpacked/aligned/" + cases.second + "/Std_MIX.txt";
        std::string origpath = "reader/bin/toPack/" + cases.second + ".txt";

        obj.readProcessing( inpath, outpath );


        std::ifstream originFile(  origpath );
        std::ifstream unpackedFile( outpath );

        if( ( !originFile.is_open() ) || ( !unpackedFile.is_open() ) ) {

            throw std::runtime_error( "cant open files for testing" );

        } else {


            std::string orig_str;
            std::string unpack_str;

            while( !originFile.eof() ) {

                std::getline( originFile, orig_str );
                std::getline( unpackedFile, unpack_str );

                ASSERT_EQ( orig_str, unpack_str );


            }

        }
    }
}

TEST( ReaderTests, alignedType_MagicProtMIX_CorrectValues ) {

    std::map< int, string > files;
    files[ 0 ] = "twenty_enter";
    files[ 1 ] = "empty";
    files[ 2 ] = "one_sym";
    files[ 3 ] = "rand_lines";
    files[ 4 ] = "rand_sym";
    for( const auto& cases : files ) {

        DataRead obj;
// std::cerr << "test\t" << cases.first << "\n";

        std::string inpath = "reader/bin/toRead/packed/aligned/" + cases.second + "/Mag_MIX.txt";
        std::string outpath = "reader/bin/toRead/unpacked/aligned/" + cases.second + "/Mag_MIX.txt";
        std::string origpath = "reader/bin/toPack/" + cases.second + ".txt";

        obj.readProcessing( inpath, outpath );


        std::ifstream originFile(  origpath );
        std::ifstream unpackedFile( outpath );

        if( ( !originFile.is_open() ) || ( !unpackedFile.is_open() ) ) {

            throw std::runtime_error( "cant open files for testing" );

        } else {


            std::string orig_str;
            std::string unpack_str;

            while( !originFile.eof() ) {

                std::getline( originFile, orig_str );
                std::getline( unpackedFile, unpack_str );

                ASSERT_EQ( orig_str, unpack_str );


            }

        }
    }
}

TEST( ReaderTests, randomType_StandartProt_CorrectValues ) {

    std::map< int, string > files;
    files[ 0 ] = "twenty_enter";
    files[ 1 ] = "empty";
    files[ 2 ] = "one_sym";
    files[ 3 ] = "rand_lines";
    files[ 4 ] = "rand_sym";
    for( const auto& cases : files ) {

        DataRead obj;
        // std::cerr << "test\t" << cases.first << "\n";

        std::string inpath = "reader/bin/toRead/packed/random/" + cases.second + "/Std.txt";
        std::string outpath = "reader/bin/toRead/unpacked/random/" + cases.second + "/Std.txt";
        std::string origpath = "reader/bin/toPack/" + cases.second + ".txt";

        obj.readProcessing( inpath, outpath );


        std::ifstream originFile(  origpath );
        std::ifstream unpackedFile( outpath );

        if( ( !originFile.is_open() ) || ( !unpackedFile.is_open() ) ) {

            throw std::runtime_error( "cant open files for testing" );

        } else {


            std::string orig_str;
            std::string unpack_str;

            while( !originFile.eof() ) {

                std::getline( originFile, orig_str );
                std::getline( unpackedFile, unpack_str );

                ASSERT_EQ( orig_str, unpack_str );


            }

        }
    }
}

TEST( ReaderTests, randomType_MagicProt_CorrectValues ) {

    std::map< int, string > files;
    files[ 0 ] = "twenty_enter";
    files[ 1 ] = "empty";
    files[ 2 ] = "one_sym";
    files[ 3 ] = "rand_lines";
    files[ 4 ] = "rand_sym";
    for( const auto& cases : files ) {

        DataRead obj;
        // std::cerr << "test\t" << cases.first << "\n";

        std::string inpath = "reader/bin/toRead/packed/random/" + cases.second + "/Mag.txt";
        std::string outpath = "reader/bin/toRead/unpacked/random/" + cases.second + "/Mag.txt";
        std::string origpath = "reader/bin/toPack/" + cases.second + ".txt";

        obj.readProcessing( inpath, outpath );


        std::ifstream originFile(  origpath );
        std::ifstream unpackedFile( outpath );

        if( ( !originFile.is_open() ) || ( !unpackedFile.is_open() ) ) {

            throw std::runtime_error( "cant open files for testing" );

        } else {


            std::string orig_str;
            std::string unpack_str;

            while( !originFile.eof() ) {

                std::getline( originFile, orig_str );
                std::getline( unpackedFile, unpack_str );

                ASSERT_EQ( orig_str, unpack_str );


            }

        }
    }
}

TEST( ReaderTests, randomType_StandartProtMIX_CorrectValues ) {

    std::map< int, string > files;
    files[ 0 ] = "twenty_enter";
    files[ 1 ] = "empty";
    files[ 2 ] = "one_sym";
    files[ 3 ] = "rand_lines";
    files[ 4 ] = "rand_sym";
    for( const auto& cases : files ) {

        DataRead obj;
        // std::cerr << "test\t" << cases.first << "\n";

        std::string inpath = "reader/bin/toRead/packed/random/" + cases.second + "/Std_MIX.txt";
        std::string outpath = "reader/bin/toRead/unpacked/random/" + cases.second + "/Std_MIX.txt";
        std::string origpath = "reader/bin/toPack/" + cases.second + ".txt";

        obj.readProcessing( inpath, outpath );


        std::ifstream originFile(  origpath );
        std::ifstream unpackedFile( outpath );

        if( ( !originFile.is_open() ) || ( !unpackedFile.is_open() ) ) {

            throw std::runtime_error( "cant open files for testing" );

        } else {


            std::string orig_str;
            std::string unpack_str;

            while( !originFile.eof() ) {

                std::getline( originFile, orig_str );
                std::getline( unpackedFile, unpack_str );

                ASSERT_EQ( orig_str, unpack_str );


            }

        }
    }
}

TEST( ReaderTests, randomType_MagicProtMIX_CorrectValues ) {

    std::map< int, string > files;
    files[ 0 ] = "twenty_enter";
    files[ 1 ] = "empty";
    files[ 2 ] = "one_sym";
    files[ 3 ] = "rand_lines";
    files[ 4 ] = "rand_sym";
    for( const auto& cases : files ) {

        DataRead obj;
        // std::cerr << "test\t" << cases.first << "\n";

        std::string inpath = "reader/bin/toRead/packed/random/" + cases.second + "/Mag_MIX.txt";
        std::string outpath = "reader/bin/toRead/unpacked/random/" + cases.second + "/Mag_MIX.txt";
        std::string origpath = "reader/bin/toPack/" + cases.second + ".txt";

        obj.readProcessing( inpath, outpath );


        std::ifstream originFile(  origpath );
        std::ifstream unpackedFile( outpath );

        if( ( !originFile.is_open() ) || ( !unpackedFile.is_open() ) ) {

            throw std::runtime_error( "cant open files for testing" );

        } else {


            std::string orig_str;
            std::string unpack_str;

            while( !originFile.eof() ) {

                std::getline( originFile, orig_str );
                std::getline( unpackedFile, unpack_str );

                ASSERT_EQ( orig_str, unpack_str );


            }

        }
    }
}


#include <gtest/gtest.h>
#include "dataRead/dataRead.h"

TEST( ReaderTests, creating ) {

    DataRead obj;
}

TEST( ReaderTests, Alig_Std ) {

    DataRead obj;
    std::string inpath = "reader/aligned/packed/Std.txt";
    std::string outpath = "reader/aligned/unpacked/Std.txt";
    obj.read_processing( inpath, outpath );

    std::string origpath = "reader/randsym.txt";

    std::ifstream originFile(  origpath );
    std::ifstream unpackedFile( outpath );

    if( ( !originFile.is_open() ) || ( !unpackedFile.is_open() ) ) {

        throw std::runtime_error( "cant open file for testing" );

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

TEST( ReaderTests, Alig_Std_MIX ) {

    DataRead obj;
    std::string inpath = "reader/aligned/packed/Std_MIX.txt";
    std::string outpath = "reader/aligned/unpacked/Std_MIX.txt";
    obj.read_processing( inpath, outpath );

    std::string origpath = "reader/randsym.txt";

    std::ifstream originFile(  origpath );
    std::ifstream unpackedFile( outpath );

    if( ( !originFile.is_open() ) || ( !unpackedFile.is_open() ) ) {

        throw std::runtime_error( "cant open file " );

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

TEST( ReaderTests, Alig_Mag ) {

    DataRead obj;
    std::string inpath = "reader/aligned/packed/Mag.txt";
    std::string outpath = "reader/aligned/unpacked/Mag.txt";
    obj.read_processing( inpath, outpath );

    std::string origpath = "reader/randsym.txt";
    std::ifstream originFile(  origpath );
    std::ifstream unpackedFile( outpath );

    if( ( !originFile.is_open() ) || ( !unpackedFile.is_open() ) ) {

        throw std::runtime_error( "cant open file " );

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

TEST( ReaderTests, Alig_Mag_MIX ) {

    DataRead obj;
    std::string inpath = "reader/aligned/packed/Mag_MIX.txt";
    std::string outpath = "reader/aligned/unpacked/Mag_MIX.txt";
    obj.read_processing( inpath, outpath );

    std::string origpath = "reader/randsym.txt";
    std::ifstream originFile(  origpath );
    std::ifstream unpackedFile( outpath );

    if( ( !originFile.is_open() ) || ( !unpackedFile.is_open() ) ) {

        throw std::runtime_error( "cant open file " );

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

TEST( ReaderTests, Rand_Std ) {

    DataRead obj;
    std::string inpath = "reader/random/packed/Std.txt";
    std::string outpath = "reader/random/unpacked/Std.txt";
    obj.read_processing( inpath, outpath );

    std::string origpath = "reader/randsym.txt";

    std::ifstream originFile(  origpath );
    std::ifstream unpackedFile( outpath );

    if( ( !originFile.is_open() ) || ( !unpackedFile.is_open() ) ) {

        throw std::runtime_error( "cant open file " );

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

TEST( ReaderTests, Rand_Std_MIX ) {

    DataRead obj;
    std::string inpath = "reader/random/packed/Std_MIX.txt";
    std::string outpath = "reader/random/unpacked/Std_MIX.txt";
    obj.read_processing( inpath, outpath );

    std::string origpath = "reader/randsym.txt";

    std::ifstream originFile(  origpath );
    std::ifstream unpackedFile( outpath );

    if( ( !originFile.is_open() ) || ( !unpackedFile.is_open() ) ) {

        throw std::runtime_error( "cant open file " );

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

TEST( ReaderTests, Rand_Mag ) {

    DataRead obj;
    std::string inpath = "reader/random/packed/Mag.txt";
    std::string outpath = "reader/random/unpacked/Mag.txt";
    obj.read_processing( inpath, outpath );

    std::string origpath = "reader/randsym.txt";

    std::ifstream originFile(  origpath );
    std::ifstream unpackedFile( outpath );

    if( ( !originFile.is_open() ) || ( !unpackedFile.is_open() ) ) {

        throw std::runtime_error( "cant open file " );

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

TEST( ReaderTests, Rand_Mag_MIX ) {

    DataRead obj;
    std::string inpath = "reader/random/packed/Mag_MIX.txt";
    std::string outpath = "reader/random/unpacked/Mag_MIX.txt";
    obj.read_processing( inpath, outpath );

    std::string origpath = "reader/randsym.txt";

    std::ifstream originFile(  origpath );
    std::ifstream unpackedFile( outpath );

    if( ( !originFile.is_open() ) || ( !unpackedFile.is_open() ) ) {

        throw std::runtime_error( "cant open file " );

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

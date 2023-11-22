#include <gtest/gtest.h>
#include "dataRead.h"

TEST( ReaderTests, creating ) {

    DataRead obj;
}

TEST( ReaderTests, Alig_Std ) {

    DataRead obj;
    std::string inpath = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/bin/reader/aligned/aligned_Std.txt";
    std::string outpath = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/bin/reader/aligned/unpacked/aligned_Std.txt";
    obj.readFromFile( inpath, outpath );

    std::string origpath = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/bin/reader/originCodeforReader.txt";
    std::ifstream originFile(  origpath );
    std::ifstream unpackedFile( outpath );

    if( ( !originFile.is_open() ) | ( !unpackedFile.is_open() ) ) {

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
    std::string inpath = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/bin/reader/aligned/aligned_Mag.txt";
    std::string outpath = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/bin/reader/aligned/unpacked/aligned_Mag.txt";
    obj.readFromFile( inpath, outpath );

    std::string origpath = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/bin/reader/originCodeforReader.txt";
    std::ifstream originFile(  origpath );
    std::ifstream unpackedFile( outpath );

    if( ( !originFile.is_open() ) | ( !unpackedFile.is_open() ) ) {

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

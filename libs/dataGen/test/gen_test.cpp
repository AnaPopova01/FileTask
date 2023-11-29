#include <gtest/gtest.h>
#include "dataGen/dataGen.h"

TEST( GeneratorTests, creating ) {

    DataGenerator obj;
}

TEST( GeneratorTests, openAndConfig ) {

    DataGenerator obj;
    try {
        obj.readConfig( "tatus" );
    } catch( std::runtime_error& e ) {

        ASSERT_STREQ( e.what(), "cant open file " );
        // std::cerr << e.what() << std::endl;

    }
    std::string path = "generator/test_config.txt";

    obj.readConfig( path );
    ASSERT_EQ( 50, obj.getN() );
    ASSERT_EQ( '#', obj.getSym() );
    ASSERT_EQ( 100, obj.getK() );

}

TEST( GeneratorTests, writeToFile ) {

    DataGenerator obj;

    std::string confpath = "generator/test_config.txt";
    obj.readConfig( confpath );

    std::string outputPath = "generator/test_gen_data.txt";
    obj.writeToFile( outputPath );

    std::ifstream originFile( outputPath ); // open file with origin strings

    if( !originFile.is_open() ) {

        throw std::runtime_error( "cant open file " );

    } else {

        std::string str;

        while( !originFile.eof() ) {

            std::getline( originFile, str );


        }
        ASSERT_GT( str.size(), 0 );
        ASSERT_LE( str.size(), obj.getMaxLen() * obj.getK() );
        ASSERT_EQ( str.find( '&' ), std::string::npos );


    }

}


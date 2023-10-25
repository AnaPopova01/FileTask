#include <gtest/gtest.h>
#include "dataGen.h"

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
    std::string path = "dat/test_config.txt";

    obj.readConfig( path );
    ASSERT_EQ( 10, obj.getN() );
    ASSERT_EQ( '#', obj.getSym() );
    ASSERT_EQ( 20, obj.getK() );

}

TEST( GeneratorTests, writeToFile ) {

    DataGenerator obj;

    std::string confpath = "dat/test_config.txt";
    obj.readConfig( confpath );

    std::string outputPath = "dat/test_gen_data.txt";
    obj.writeToFile( outputPath );

    std::ifstream originFile( outputPath ); // open file with origin strings

    if( !originFile.is_open() ) {

        throw std::runtime_error( "cant open file " );

    } else {

        uint32_t counter = 0;
        std::string str;

        while( !originFile.eof() ) {

            std::getline( originFile, str );
            counter++;
            ASSERT_LE( str.size(), obj.getMaxLen() );

        }
        ASSERT_EQ( counter, obj.getK() );

    }

}


#include <gtest/gtest.h>
#include "dataGen/dataGen.h"

TEST( GeneratorTests, readConfig_openConfigFile_runtimeError ) {

    DataGenerator obj;
    try {
        obj.readConfig( "tatus" );
    } catch( std::runtime_error& e ) {

        ASSERT_STREQ( e.what(), "cant open config file" );

    }
}

TEST( GeneratorTests, readConfig_readValues_CorrectValues ) {

    DataGenerator obj;

    std::string path = "generator/correct_val_conf.txt";

    obj.readConfig( path );
    ASSERT_EQ( 50, obj.getN() );
    ASSERT_EQ( '#', obj.getSym() );
    ASSERT_EQ( 100, obj.getK() );

}

TEST( GeneratorTests, readConfig_readValues_NullPackSize ) {

    DataGenerator obj;

    std::string path = "generator/null_N_conf.txt";

    try {
        obj.readConfig( path );
    } catch( std::runtime_error& e ) {

        ASSERT_STREQ( e.what(), "null value of package length in configFile" );


    }

}
TEST( GeneratorTests, readConfig_readValues_NullAmountOfString ) {

    DataGenerator obj;

    std::string path = "generator/null_k_conf.txt";

    try {
        obj.readConfig( path );
    } catch( std::runtime_error& e ) {


        ASSERT_STREQ( e.what(), "null value of quantity of strings in configFile" );

    }

}


TEST( GeneratorTests, writeToFile_writeOutputValues_correctValues ) {

    DataGenerator obj;

    std::string configPath = "generator/correct_val_conf.txt";
    obj.readConfig( configPath );

    std::string outputPath = "generator/test_gen_data.txt";
    obj.writeToFile( outputPath );

    std::ifstream originFile( outputPath ); // open file with origin strings

    if( !originFile.is_open() ) {

        throw std::runtime_error( "cant open output test file for dataGen" );

    } else {

        std::string str;

        while( !originFile.eof() ) {

            std::getline( originFile, str );


        }
        ASSERT_GT( str.size(), 1 * obj.getK() );
        ASSERT_LE( str.size(), obj.getMaxLen() * obj.getK() );
        ASSERT_EQ( str.find( '&' ), std::string::npos );


    }

}


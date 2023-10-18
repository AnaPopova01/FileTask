#include <gtest/gtest.h>
#include "dataGen.h"

TEST( GeneratorTests, creating ) {

    DataGenerator obj;
}

TEST( GeneratorTests, opening ) {

    DataGenerator obj;
    try {
        obj.readConfig( "tatus" );
    } catch( std::runtime_error& e )   {

        ASSERT_STREQ( e.what(), "cant open file " );
        std::cerr << e.what() << std::endl;

    }
}


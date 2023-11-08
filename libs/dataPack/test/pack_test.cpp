#include <gtest/gtest.h>
#include "src/dataPack.h"
#include "src/randPack.h"
#include "include/packerfactory.h"

TEST( WriterTests, creating ) {

    auto tatus = createPackerImpl();
    tatus->writeToFile();
}

#include <gtest/gtest.h>
#include "dataRead.h"

TEST( ReaderTests, creating ) {

    DataRead obj;
}

TEST( ReaderTests, readFromFile ) {

    DataRead obj;
    std::string inpath = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/bin/to_read/random_Mag.txt";
    std::string outpath = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/bin/from_read/test.txt";
    obj.readFromFile( inpath, outpath );
}

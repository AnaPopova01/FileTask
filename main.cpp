#include <iostream>
#include "libs/dataGen/dataGen.h"
#include "libs/dataPack/src/dataPack.h"
#include "libs/dataPack/src/randPack.h"
#include "src/dataPack.h"
#include "src/randPack.h"
#include "include/packerfactory.h"


// в качестве аргумента main кидаем название файла конфигурации (или путь к нему если он не в папке с бинарником), чтобы можно было его вызвать из консоли (сигнатура в тетради)

int main() {

// DataGenerator obj;

// std::string confpath = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/bin/config.txt";
// obj.readConfig( confpath );

// std::string outputPath = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/bin/randOrigCode.txt";
// obj.writeToFile( outputPath );


    auto tatus = createPackerImpl( PackerType::Aligned );
    Protocol prot { ProtocolType::Standart,  50, 0 };

    const string inputfile = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/bin/randOrigCode.txt";
    const string outputfile = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/bin/reader/cursedaligned_Std.txt";
    tatus->writeToFile( inputfile, outputfile, prot );
}

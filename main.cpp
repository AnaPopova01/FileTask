#include <iostream>
#include "libs/dataGen/dataGen.h"
#include "libs/dataPack/src/dataPack.h"
#include "libs/dataPack/src/randPack.h"
#include "src/dataPack.h"
#include "src/randPack.h"
#include "include/packerfactory.h"


// в качестве аргумента main кидаем название файла конфигурации (или путь к нему если он не в папке с бинарником), чтобы можно было его вызвать из консоли (сигнатура в тетради)

int main() {

    auto tatus = createPackerImpl( PackerType::Random );
    Protocol prot { ProtocolType::Magic,  50, 0 };

    const string inputfile = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/bin/from_read/originCodeforReader.txt";
    const string outputfile = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/bin/to_read/random_Mag.txt";
    tatus->writeToFile( inputfile, outputfile, prot );
}

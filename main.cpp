#include <iostream>

 #include "libs/dataPack/include/dataPack/basepack.h"
 #include "libs/dataPack/include/dataPack/packerfactory.h"

 #include "libs/dataRead/include/dataRead/dataRead.h"


// в качестве аргумента main кидаем название файла конфигурации (или путь к нему если он не в папке с бинарником), чтобы можно было его вызвать из консоли (сигнатура в тетради)

using std::string;
int main() {

    auto tatus = createPackerImpl( PackerType::Aligned );
    Protocol prot { ProtocolType::Standart,  9, 0 };

    const string toPack = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/bin/lolol.txt";
    const string packed = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/bin/packed_lolol.txt";
    const string toRead = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/bin/unpacked_lolol.txt";

    tatus->pack_processing( toPack, packed, prot );

    DataRead reader;
    reader.read_processing( packed, toRead );

}


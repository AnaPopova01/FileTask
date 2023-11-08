#include <iostream>
#include "libs/dataGen/dataGen.h"
#include "libs/dataPack/src/dataPack.h" // потом заменить на фабрику
#include "libs/dataPack/src/randPack.h"

struct Header {
    // const uint32_t magic{ ABOBA };
    uint32_t counter;
    uint32_t size; // random (1:N)
};

// в качестве аргумента main кидаем название файла конфигурации (или путь к нему если он не в папке с бинарником), чтобы можно было его вызвать из консоли (сигнатура в тетради)

int main() {

// DataGenerator obj;
// std::string confpath = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/config.txt";
// obj.readConfig( confpath );
// std::string origstrPath = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/originCode.txt";
//// obj.writeToFile( origstrPath );

//// uint32_t maxPackLen = obj.getN();
// uint32_t maxPackLen = 50;

// AlignedWriter packer( origstrPath, maxPackLen );
// std::string outpath = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/packedCode.txt";
// packer.writeToFile( outpath );


// uint32_t magic = 0xBABADEDA;
// std::cerr << " magic: " << magic << "\n";

// return 0;
}

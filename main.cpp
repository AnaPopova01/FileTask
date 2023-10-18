#include <iostream>
#include "libs/dataGen/dataGen.h"
#include "libs/dataWrite/dataWrite.h"

struct Header {
    const uint32_t magic{ 0000000 };
    uint32_t counter;
    uint32_t size; // random (1:N)
};


int main() {  // в качестве аргумента main кидаем название файла конфигурации (или путь к нему если он не в папке с бинарником), чтобы можно было его вызвать из консоли (сигнатура в тетради)

    DataGenerator obj;
    std::string inpath = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/config.txt";
    obj.readConfig( inpath );
    // obj.writeToFile( inpath );

    // uint32_t maxPackLen = obj.getN();
    uint32_t maxPackLen = 50;

    DataWrite packer( inpath, maxPackLen );
    std::string outpath = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/packetCode.txt";
    packer.writeFile( outpath );


    uint32_t magic = 0xBABADEDA;
    std::cerr << " magic: " << magic << "\n";

    return 0;
}

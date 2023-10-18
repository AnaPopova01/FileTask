#include <iostream>
#include "libs/dataGеn/dataGеn.h"
#include "libs/dataWrite/dataWrite.h"

using namespace std;

// what if N нечетный
// динамический размер на инфу для данных и заголовка
// нахуя подзаголовки к данным

int main() {

    DataGеnerator obj;
    obj.readConfig();
    string inpath = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/originCode.txt";
    // obj.writeToFile( inpath );

    DataWrite packer( inpath, obj.getN() );
    string outpath = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/packetCode.txt";
    packer.writeFile( outpath );


    return 0;
}

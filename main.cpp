#include <iostream>
#include "libs/dataGеn/dataGеn.h"
#include "libs/dataWrite/dataWrite.h"

using namespace std;

int main() {

    DataGеnerator obj;
    obj.readConfig();
    string path = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/originCode.txt";
    // obj.writeToFile( path );

    DataWrite packer( path, obj.getN() );
    packer.readFile();


    return 0;
}

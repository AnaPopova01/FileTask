#include <iostream>
#include "libs/dataGеn/dataGеn.h"

using namespace std;

int main() {

    DataGеnerator obj;
    obj.readConfig();
    string path = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/originCode.txt";

    obj.writeToFile( path );


    return 0;
}

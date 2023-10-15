#include <iostream>
#include "libs/writer/writer.h"

using namespace std;

int main() {

    Writer obj;
    obj.readConfig();
    string path = "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/originCode.txt";
    obj.genData();
    obj.writeToFile( path );


    return 0;
}

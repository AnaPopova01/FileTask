#include "dataWrite.h"
#include <iostream>

DataWrite::DataWrite( std::string& path, uint32_t Num ) {
    this->N = Num;
    this->path = path;
}

void DataWrite::readFile() {

    std::ifstream originFile( path );
    if( !originFile.is_open() ) {

        throw std::runtime_error( "cant open file " );

    } else {

        std::ofstream outfile( "/home/ann/WORK/work_qt/StringCoder/FilesAndStrings/packetCode.txt" );

        uint32_t packNum = 0;
        std::string str;
        while( !originFile.eof() ) {

            std::getline( originFile, str );
            outfile << "номер пакета " << packNum << "\t";
            outfile << "макс размер пакета " << N << "\t" << "\n";
            outfile << "пакет: " << "\n";
            str = std::to_string( packNum ) + std::to_string( N ) + str;
            outfile << str << "\t" << str.size() << "\n";
            packNum++;
        }

// открыть файл
// цикл пока не дойдем до конца файла
// прочитать строку
// добавить служебную инфу
// влезет ли строка в текущий пакет заданной длины с учетом служебной инфы?
// если да то записать в файл     если нет то разбить на подстроки, записать что влезет а остаток в следующий пакет

        outfile.close();



        // std::cerr << str;


    }
}


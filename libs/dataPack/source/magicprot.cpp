 #include "magicprot.h"


void MagicProt::setProtocol( Protocol& protocol ) {


    this->prot = protocol;

    headerSize = k_in_1stHead + k_in_2ndHead + ( std::to_string( keyword ) ).size();

    this->serviceDataFieldLen = 0;
    this->maxSpace = prot.N - headerSize;

    resetPackSpace();
}


void MagicProt::writeToFile( const std::string& outputfile ) {

    this->outfile.open( outputfile, std::ios::binary ); // open file to write
    if( !outfile.is_open() ) {

        throw std::runtime_error( "cant open output packer file " );

    } else {

        formPack();
        printvecdata();
    }
    outfile.close();
}

void MagicProt::finishPack( std::string& str ) { // also add pack to common vector

    addHeadInfo( str );
    vecdata.push_back( str );
}


void MagicProt::addHeadInfo( std::string& str ) {

    std::string header = std::to_string( keyword );
    std::string header1 = std::to_string( currpackNum );
    while( header1.size() != k_in_1stHead ) {
        header1 = "0" + header1;
    }
    std::string header2 = std::to_string( kOfSym );
    while( header2.size() != k_in_2ndHead ) {
        header2 = "0" + header2;
    }
    str = header + header1 + header2 + str;
    // outfile << header << "\t" << header1 << "\t" << header2 << "\t";

}



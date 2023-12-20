#ifndef RANDOMPACKER_H
#define RANDOMPACKER_H
#include "ipacker.h"
#include "basepack.h"

class MagicProt: public BaseImpl {

public:

    MagicProt( PackerType prtype ) {
        this->type = prtype;
    }


private:

    void setProtocol( Protocol& protocol ) override final;
    void writeToFile( const std::string& outputfile ) override final;
    void finishPack( std::string& str ) override final;
    void addHeadInfo( std::string& str );

    unsigned int keyword = 0xDED;
};
#endif // RANDOMPACKER_H

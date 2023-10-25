#pragma once


class IPacker {
public:

    // no constructor
    virtual void writeToFile( const std::string& outpath ) = 0;

};

#pragma once
#include <cstdint>
#include <iostream>

// Standart - добавляет подзаголовок к данным и выравнивает пакет до фиксированной длины, заголовок состоит только из порядкового номера пакета
// Magic - добавляет подзаголовок к данным,заголовок состоит ключевого слова, порядкового номера пакета и его длины


enum class ProtocolType : uint32_t { Standart = 0, Magic = 1 };
enum class PackerType : uint32_t { Aligned = 0, Random = 1 };


struct Protocol {
    ProtocolType type;
    uint16_t N; // max length of packet
    bool mixPackets { false };
};


class IPacker {
public:
    virtual void packProcessing( const std::string& inputfile, const std::string& outputfile, Protocol& prot ) = 0;
};



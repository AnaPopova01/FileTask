#include "dataRead.h"

// Standart - добавляет подзаголовок к данным и выравнивает пакет до фиксированной длины, заголовок состоит только из порядкового номера пакета
// Magic - добавляет подзаголовок к данным,заголовок состоит ключевого слова, порядкового номера пакета и его длины


DataRead::DataRead() {

}

// open file
// read first string
// if first 4 symbols is 0000 then it is std-protocol, if first 4 symbols is 3565 then it is mag-protocol
// if std-prot then strtoint(first 4 sym) and erase then from string
// a = 0; if they >=a then vec.pushback else vec.push_front

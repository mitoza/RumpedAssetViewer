//
// Created by Dmitry Velychko on 12.07.2024.
//

#ifndef ASSETVIEWER_XMPFORMAT_H
#define ASSETVIEWER_XMPFORMAT_H

#include <string>

class XMPFormat {


public:
    std::string encode(const unsigned char *data, std::size_t dataSize);

    std::vector<unsigned char> decode(std::string data);

};


#endif //ASSETVIEWER_XMPFORMAT_H

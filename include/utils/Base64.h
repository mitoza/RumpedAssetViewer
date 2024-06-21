//
// Created by Dmitry Velychko on 21.06.2024.
//

#ifndef ASSETVIEWER_BASE64_H
#define ASSETVIEWER_BASE64_H

#include <string>
#include <vector>

namespace rumpedav {

    static const char* base64CharactersTable = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

// The following table maps each character from base64CharactersTable to its index in the table.
// All characters that don't appear in base64CharactersTable are mapped to 255. Valid indices are in range [0,63]
    static const std::uint8_t base64InverseCharactersTable[256] = {
            255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,  // [  0 -  15]
            255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,  // [ 16 -  31]
            255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,  62, 255, 255, 255,  63,  // [ 32 -  47]
            52,  53,  54,  55,  56,  57,  58,  59,  60,  61, 255, 255, 255, 255, 255, 255,  // [ 48 -  63]
            255,   0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13,  14,  // [ 64 -  79]
            15,  16,  17,  18,  19,  20,  21,  22,  23,  24,  25, 255, 255, 255, 255, 255,  // [ 80 -  95]
            255,  26,  27,  28,  29,  30,  31,  32,  33,  34,  35,  36,  37,  38,  39,  40,  // [ 96 - 111]
            41,  42,  43,  44,  45,  46,  47,  48,  49,  50,  51, 255, 255, 255, 255, 255,  // [112 - 128]
            255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,  // [128 - 143]
            255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,  // [144 - 159]
            255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,  // [160 - 175]
            255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,  // [176 - 191]
            255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,  // [192 - 207]
            255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,  // [208 - 223]
            255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,  // [224 - 239]
            255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255}; // [240 - 255]
    class Base64 {
    public:
        static std::string encode(const std::uint8_t *data, std::size_t nrBytes);

        static std::vector<std::uint8_t> decode(std::string_view data);
    };

}

#endif //ASSETVIEWER_BASE64_H

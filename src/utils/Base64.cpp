//
// Created by Dmitry Velychko on 21.06.2024.
//

#include "../../include/utils/Base64.h"

namespace rumpedav {

    std::string Base64::encode(const unsigned char *data, std::size_t nrBytes) {
        std::string result;

        const std::size_t nrBytesWithPadding = ((nrBytes + 2) / 3) * 3;
        result.reserve((nrBytesWithPadding * 8) / 6);

        unsigned int val = 0;
        int valShift = -6;
        for (std::size_t i = 0; i < nrBytes; ++i) {
            val = (val << 8) + data[i];
            valShift += 8;
            while (valShift >= 0) {
                result.push_back(base64CharactersTable[(val >> valShift) & 0b00111111]);
                valShift -= 6;
            }
        }

        if (valShift > -6)
            result.push_back(base64CharactersTable[((val << 8) >> (valShift + 8)) & 0b00111111]);

        // Add padding bytes if needed
        while (result.size() % 4)
            result.push_back('=');

        return result;
    }

    std::vector<unsigned char> Base64::decode(std::string data) {
        // Reserve space for the result. This might reserve up to 2 bytes more than needed if data is padded.
        std::vector<unsigned char> result;
        result.reserve(data.length() * 6 / 8);

        unsigned int val = 0;
        int valShift = -8;
        for (char c: data) {
            const unsigned char tableIndex = base64InverseCharactersTable[static_cast<unsigned char>(c)]; // NOLINT(cppcoreguidelines-pro-bounds-constant-array-index)

            // Stop the decoding when an invalid character is encountered.
            // Since we don't check for it explicitly, this case will also happen when we reach a padding byte at the end.
            if (tableIndex == 255)
                break;

            val = (val << 6) + tableIndex;
            valShift += 6;
            if (valShift >= 0) {
                result.push_back(static_cast<unsigned char>((val >> valShift) & 0xFF));
                valShift -= 8;
            }
        }

        return result;
    }

}
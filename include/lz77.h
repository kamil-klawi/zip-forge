//
// Created by kamil on 6/29/25.
//

#ifndef LZ77_H
#define LZ77_H

#include <string>

namespace LZ77 {
    std::string compress(const std::string& text);
    std::string decompress(const std::string& encoded);
}

#endif //LZ77_H

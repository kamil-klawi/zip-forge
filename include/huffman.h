//
// Created by kamil on 6/29/25.
//

#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <string>

namespace Huffman {
    std::string compress(const std::string& text);
    std::string decompress(const std::string& encoded);
}

#endif //HUFFMAN_H

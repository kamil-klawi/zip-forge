//
// Created by kamil on 6/29/25.
//

#include <vector>
#include <format>

#include "../include/lz77.h"

namespace LZ77 {
    struct Token {
        int offset;
        int length;
        char next;
    };

    Token findLongestMatch(const std::string& text, int position, int window_size) {
        int longest_length = 0;
        int longest_offset = 0;
        int start_position = std::max(0, position - window_size);

        for (int i = start_position; i < position; i++) {
            int length = 0;

            while (
                position + length < text.size() &&
                text[i + length] == text[position + length]
                ) {
                ++length;
                }

            if (length > longest_length) {
                longest_length = length;
                longest_offset = position - i;
            }
        }

        char nextChar = (position + longest_length < text.size()) ? text[position + longest_length] : '\0';
        return { longest_offset, longest_length, nextChar };
    }

    std::vector<Token> compressLZ77(const std::string& text, int window_size = 20) {
        std::vector<Token> tokens;
        int position = 0;

        while (position < text.size()) {
            Token match = findLongestMatch(text, position, window_size);
            tokens.push_back(match);
            position += match.length + 1;
        }

        return tokens;
    }

    std::string compress(const std::string& text) {
        std::vector<Token> tokens = compressLZ77(text);
        std::string result;

        for (const auto& token : tokens) {
            result = std::format("({}, {}, {})", token.offset, token.length, token.next);
        }
        return result;
    }
}

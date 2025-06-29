#include <iostream>
#include <limits>

#include "../include/huffman.h"
#include "../include/lz77.h"

int main() {
    int choice;
    std::string compressed, decompressed;

    while (choice != 4) {
        std::cout << "Select an algorithm:\n1. Huffman\n2. LZ77\n3. RLE\n4. Exit (leave the app)\n> ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 4) {
            std::cout << "Exit\n";
            return EXIT_SUCCESS;
        }

        std::cout << "Enter the text you want to compress\n";
        std::string input;
        std::getline(std::cin, input);
        switch (choice) {
            case 1:
                std::cout << "Selected: HUFFMAN\n";
                compressed = Huffman::compress(input);
                std::cout << "Compressed text: " << compressed << "\n";
                break;
            case 2:
                std::cout << "Selected: LZ77\n";
                compressed = LZ77::compress(input);
                std::cout << "Compressed text: " << compressed << "\n";
                break;
            case 3:
                std::cout << "Selected: RLE\n";
                break;
            default:
                std::cout << "The algorithm you are looking for does not exist!\n";
                break;
        }
    }
    return EXIT_SUCCESS;
}

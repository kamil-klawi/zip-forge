//
// Created by kamil on 6/29/25.
//

#include <queue>
#include <unordered_map>

#include "../include/huffman.h"

namespace Huffman {
    struct Node {
        char character;
        int freq;
        Node *left, *right;

        Node(const char character, const int freq) : character(character), freq(freq), left(nullptr), right(nullptr) {}
        Node(Node *left, Node *right) : character('\0'), freq(left -> freq + right -> freq), left(left), right(right) {}
    };

    struct Compare {
        bool operator()(const Node *left, const Node *right) const {
            return left->freq > right->freq;
        };
    };

    void binaryCode(const Node *root, const std::string& text, std::unordered_map<char, std::string>& map) {
        if (!root)
            return;

        if (!root->left && !root->right) {
            map[root->character] = !text.empty() ? text : "0";
        }

        binaryCode(root->left, text + "0", map);
        binaryCode(root->right, text + "1", map);
    }

    void freeTree(const Node* root) {
        if (!root)
            return;

        freeTree(root->left);
        freeTree(root->right);
        delete root;
    }

    std::string compress(const std::string& text) {
        if (text.empty())
            return "";

        std::unordered_map<char, int> freq;
        for (char character : text) freq[character]++;

        std::priority_queue<Node*, std::vector<Node*>, Compare> priority_queue;
        for (auto pair : freq) {
            priority_queue.push(new Node(pair.first, pair.second));
        }

        while (priority_queue.size() > 1) {
            Node* left = priority_queue.top(); priority_queue.pop();
            Node* right = priority_queue.top(); priority_queue.pop();
            auto merged = new Node(left, right);
            priority_queue.push(merged);
        }

        const Node* root = priority_queue.top();
        std::unordered_map<char, std::string> code;
        binaryCode(root, "", code);

        std::string encoded;
        for (char ch : text) {
            encoded += code[ch];
        }
        freeTree(root);
        return encoded;
    }
}

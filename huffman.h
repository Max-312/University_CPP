#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <string>
#include <map>
#include <queue>

struct TreeNode {
    char data;
    int freq;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char c, int f) : data(c), freq(f), left(nullptr), right(nullptr) {}
};

struct CompareNodes {
    bool operator()(TreeNode* a, TreeNode* b) {
        return a->freq > b->freq;
    }
};

std::string encode(const std::string& text);
std::string decode(const std::string& encoded, std::map<char, std::string>& codes);

#endif
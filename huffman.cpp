#include "huffman.h"


std::string encode(const std::string& text) {
    std::map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    std::priority_queue<TreeNode*, std::vector<TreeNode*>, CompareNodes> pq;
    for (const auto& entry : freq) {
        pq.push(new TreeNode(entry.first, entry.second));
    }

    while (pq.size() > 1) {
        TreeNode* left = pq.top();
        pq.pop();
        TreeNode* right = pq.top();
        pq.pop();
        TreeNode* combined = new TreeNode('$', left->freq + right->freq);
        combined->left = left;
        combined->right = right;
        pq.push(combined);
    }

    TreeNode* root = pq.top();

    std::map<char, std::string> codes;
    std::string code;
    encodeHelper(root, code, codes);

    std::string encoded = "";
    for (char ch : text) {
        encoded += codes[ch];
    }

    return encoded;
}

void encodeHelper(TreeNode* node, std::string code, std::map<char, std::string>& codes) {
    if (!node) {
        return;
    }
    if (node->data != '$') {
        codes[node->data] = code;
    }
    encodeHelper(node->left, code + "0", codes);
    encodeHelper(node->right, code + "1", codes);
}

std::string decode(const std::string& encoded, std::map<char, std::string>& codes) {
    std::string decoded = "";
    std::string currCode = "";
    for (char ch : encoded) {
        currCode += ch;
        for (const auto& entry : codes) {
            if (entry.second == currCode) {
                decoded += entry.first;
                currCode = "";
                break;
            }
        }
    }
    return decoded;
}
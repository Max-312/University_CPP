#include "lzw.h"

std::vector<int> compress(const std::string& text) {
    std::unordered_map<std::string, int> dictionary;
    for (int i = 0; i < 256; ++i) {
        dictionary[std::string(1, i)] = i;
    }

    std::vector<int> compressed;
    std::string current = "";
    int nextCode = 256;

    for (char c : text) {
        std::string temp = current + c;
        if (dictionary.find(temp) != dictionary.end()) {
            current = temp;
        }
        else {
            compressed.push_back(dictionary[current]);
            dictionary[temp] = nextCode++;
            current = std::string(1, c);
        }
    }

    if (!current.empty()) {
        compressed.push_back(dictionary[current]);
    }

    return compressed;
}
std::string decompress(const std::vector<int>& compressed) {
    std::unordered_map<int, std::string> dictionary;
    for (int i = 0; i < 256; ++i) {
        dictionary[i] = std::string(1, i);
    }

    std::string decompressed = "";
    std::string previous = dictionary[compressed[0]];
    decompressed += previous;

    int nextCode = 256;

    for (size_t i = 1; i < compressed.size(); ++i) {
        int currentCode = compressed[i];
        std::string current;
        if (dictionary.find(currentCode) != dictionary.end()) {
            current = dictionary[currentCode];
        }
        else if (currentCode == nextCode) {
            current = previous + previous[0];
        }
        else {
            throw std::invalid_argument("Invalid compressed data");
        }
        decompressed += current;
        dictionary[nextCode++] = previous + current[0];
        previous = current;
    }

    return decompressed;
}
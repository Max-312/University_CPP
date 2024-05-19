#ifndef LZW_H
#define LZW_H

#include <string>
#include <vector>
#include <stdexcept>
#include <unordered_map>

std::vector<int> compress(const std::string& text);
std::string decompress(const std::vector<int>& compressed);

#endif 
#include "kmp.h"

std::vector<int> computePrefix(const std::string& pattern) {
    int m = pattern.size();
    std::vector<int> prefix(m);
    prefix[0] = 0;
    int k = 0;
    for (int q = 1; q < m; ++q) {
        while (k > 0 && pattern[k] != pattern[q]) {
            k = prefix[k - 1];
        }
        if (pattern[k] == pattern[q]) {
            ++k;
        }
        prefix[q] = k;
    }
    return prefix;
}

std::vector<int> getIndices(const std::string& pattern, const std::string& text) {
    int n = text.size();
    int m = pattern.size();
    std::vector<int> matches;
    std::vector<int> prefix = computePrefix(pattern);
    int q = 0;
    for (int i = 0; i < n; ++i) {
        while (q > 0 && pattern[q] != text[i]) {
            q = prefix[q - 1];
        }
        if (pattern[q] == text[i]) {
            ++q;
        }
        if (q == m) {
            matches.push_back(i - m + 1);
            q = prefix[q - 1];
        }
    }
    return matches;
}

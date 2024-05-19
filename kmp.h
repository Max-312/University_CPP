#define KMP_H_
#ifdef KMP_H_

#include <string>
#include <vector>

std::vector<int> computePrefix(const std::string& pattern);
std::vector<int> getIndices(const std::string& my_template, const std::string& text);

#endif 
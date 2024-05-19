#include "bracket.h"

bool checkBrackets(const std::string& s) {
    std::stack<char> stack;
    std::unordered_map<char, char> matchingBrackets = {
        {')', '('},
        {']', '['},
        {'}', '{'},
        {'>', '<'}
    };

    for (char ch : s) {
        if (matchingBrackets.count(ch)) { 
            if (stack.empty() || stack.top() != matchingBrackets[ch]) {
                return false; 
            }
            stack.pop(); 
        }
        else if (ch == '(' || ch == '[' || ch == '{' || ch == '<') { 
            stack.push(ch); 
        }
    }

    return stack.empty();
}

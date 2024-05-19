#include "rpn.h"


double calculateRPN(const std::string& expr) {
    std::stack<double> stack;
    std::istringstream tokens(expr);
    std::string token;

    while (tokens >> token) {
        if (std::isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) {
            // Если токен - число
            stack.push(std::stod(token));
        }
        else {
            // Если токен - оператор
            if (stack.size() < 2) {
                throw std::runtime_error("Invalid RPN expression");
            }
            double operand2 = stack.top();
            stack.pop();
            double operand1 = stack.top();
            stack.pop();

            if (token == "+") {
                stack.push(operand1 + operand2);
            }
            else if (token == "-") {
                stack.push(operand1 - operand2);
            }
            else if (token == "*") {
                stack.push(operand1 * operand2);
            }
            else if (token == "/") {
                if (operand2 == 0) {
                    throw std::runtime_error("Division by zero");
                }
                stack.push(operand1 / operand2);
            }
            else {
                throw std::runtime_error("Unknown operator: " + token);
            }
        }
    }

    if (stack.size() != 1) {
        throw std::runtime_error("Invalid RPN expression");
    }

    return stack.top();
}

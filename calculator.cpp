#include "calculator.h"


bool isBalanced(const std::string& expr) {
    std::stack<char> stack;
    for (char ch : expr) {
        if (ch == '(') {
            stack.push(ch);
        }
        else if (ch == ')') {
            if (stack.empty() || stack.top() != '(') {
                return false;
            }
            stack.pop();
        }
    }
    return stack.empty();
}

int getPrecedence(char op) {
    switch (op) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

bool isUnaryMinus(const std::string& expr, size_t pos) {
    if (expr[pos] != '-') return false;
    return pos == 0 || (!std::isdigit(expr[pos - 1]) && expr[pos - 1] != ')');
}

std::string toRPN(const std::string& expr) {
    std::stack<char> operators;
    std::stringstream output;
    size_t length = expr.length();

    for (size_t i = 0; i < length; ++i) {
        if (std::isspace(expr[i])) {
            continue;
        }
        if (std::isdigit(expr[i]) || expr[i] == '.') {
            while (i < length && (std::isdigit(expr[i]) || expr[i] == '.')) {
                output << expr[i++];
            }
            output << ' ';
            --i;
        }
        else if (expr[i] == '(') {
            operators.push(expr[i]);
        }
        else if (expr[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                output << operators.top() << ' ';
                operators.pop();
            }
            if (!operators.empty()) {
                operators.pop();
            }
        }
        else if (isOperator(expr[i])) {
            if (isUnaryMinus(expr, i)) {
                output << "0 ";
            }
            while (!operators.empty() && getPrecedence(operators.top()) >= getPrecedence(expr[i])) {
                output << operators.top() << ' ';
                operators.pop();
            }
            operators.push(expr[i]);
        }
    }

    while (!operators.empty()) {
        output << operators.top() << ' ';
        operators.pop();
    }

    return output.str();
}

double evaluateRPN(const std::string& rpn) {
    std::stack<double> stack;
    std::istringstream tokens(rpn);
    std::string token;

    while (tokens >> token) {
        if (std::isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) {
            stack.push(std::stod(token));
        }
        else {
            double operand2 = stack.top(); stack.pop();
            double operand1 = stack.top(); stack.pop();
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
                stack.push(operand1 / operand2);
            }
            else if (token == "^") {
                stack.push(std::pow(operand1, operand2));
            }
        }
    }

    return stack.top();
}

double calculate(const std::string& expr) {
    if (!isBalanced(expr)) {
        throw std::runtime_error("Unbalanced parentheses");
    }

    std::string rpn = toRPN(expr);
    return evaluateRPN(rpn);
}

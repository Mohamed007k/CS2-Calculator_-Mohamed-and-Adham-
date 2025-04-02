#include "calculator.h"
#include <iostream>
#include <stack>
#include <sstream>
#include <cctype>
#include <map>
#include <vector>
#include <cstdlib>

using namespace std;

double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }

double divide(double a, double b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero is not allowed");
    }
    return a / b;
}

long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int randomInRange(int min, int max) {
    return min + rand() % (max - min + 1);
}

map<char, int> precedence;

void initializePrecedence() {
    precedence['+'] = 1;
    precedence['-'] = 1;
    precedence['*'] = 2;
    precedence['/'] = 2;
    precedence['('] = 0;
}

vector<string> tokenize(const string& expression) {
    vector<string> tokens;
    string number;

    for (int i = 0; i < expression.size(); ++i) {
        char ch = expression[i];
        if (isdigit(ch) || ch == '.') {
            number += ch;
        } else if (ch == ' ') {
            continue;
        } else {
            if (!number.empty()) {
                tokens.push_back(number);
                number.clear();
            }
            tokens.push_back(string(1, ch));
        }
    }

    if (!number.empty()) {
        tokens.push_back(number);
    }

    return tokens;
}

vector<string> infixToPostfix(const vector<string>& tokens) {
    stack<string> operators;
    vector<string> output;

    for (int i = 0; i < tokens.size(); ++i) {
        const string& token = tokens[i];
        if (isdigit(token[0]) || (token[0] == '.' && token.length() > 1)) {
            output.push_back(token);
        } else if (token == "(") {
            operators.push(token);
        } else if (token == ")") {
            while (!operators.empty() && operators.top() != "(") {
                output.push_back(operators.top());
                operators.pop();
            }
            operators.pop();
        } else {
            while (!operators.empty() && precedence[operators.top()[0]] >= precedence[token[0]]) {
                output.push_back(operators.top());
                operators.pop();
            }
            operators.push(token);
        }
    }

    while (!operators.empty()) {
        output.push_back(operators.top());
        operators.pop();
    }

    return output;
}

double evaluatePostfix(const vector<string>& postfix) {
    stack<double> values;

    for (int i = 0; i < postfix.size(); ++i) {
        const string& token = postfix[i];
        if (isdigit(token[0]) || (token[0] == '.' && token.length() > 1)) {
            values.push(stod(token));
        } else {
            double b = values.top(); values.pop();
            double a = values.top(); values.pop();
            switch (token[0]) {
                case '+': values.push(add(a, b)); break;
                case '-': values.push(subtract(a, b)); break;
                case '*': values.push(multiply(a, b)); break;
                case '/': values.push(divide(a, b)); break;
            }
        }
    }

    return values.top();
}

double evaluateExpression(const string& expression) {
    initializePrecedence();  // Initialize precedence map
    vector<string> tokens = tokenize(expression);
    vector<string> postfix = infixToPostfix(tokens);
    return evaluatePostfix(postfix);
}

#include <bits/stdc++.h>
using namespace std;

class Operands {
public:
    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        if (op == '^') return 3;
        return 0;
    }

    bool isOperator(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
    }

    string infixToPostFix(string infix) {
        stack<char> s;
        string postfix = "";
        
        for (char c : infix) {
            if (isspace(c)) {
                continue; // Skip spaces only
            }

            if (isalnum(c)) {
                postfix += c;
            } 
            else if (c == '(') {
                s.push(c);
            } 
            else if (c == ')') {
                if (s.empty()) {
                    throw runtime_error("Mismatched parentheses");
                }
                while (!s.empty() && s.top() != '(') {
                    postfix += s.top();
                    s.pop();
                }
                if (!s.empty()) {
                    s.pop();
                }
            } 
            else if (isOperator(c)) {
                while (!s.empty() && s.top() != '(' && precedence(s.top()) >= precedence(c)) {
                    postfix += s.top();
                    s.pop();
                }
                s.push(c);
            } 
            else {
                throw runtime_error(string("Invalid character: ") + c);
            }
        }

        while (!s.empty()) {
            if (s.top() == '(') {
                throw runtime_error("Mismatched parentheses");
            }
            postfix += s.top();
            s.pop();
        }
        
        return postfix;
    }
};

int main() {
    Operands ope;
    string infix = "((a + b) ^ (a - b)) * (a ^ b - 1)";
    string postFix = ope.infixToPostFix(infix);
    cout << "The infix is : " << infix << endl;
    cout << "The postfix is : " << postFix;
    return 0;
}
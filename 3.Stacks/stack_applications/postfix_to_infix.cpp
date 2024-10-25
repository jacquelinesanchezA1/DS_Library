#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string postfixToInfix(string postfix) {
    stack<string> operands;

    for (int i = 0; i < postfix.length(); i++) {
        if (isOperator(postfix[i])) {
            string operand2 = operands.top();
            operands.pop();
            string operand1 = operands.top();
            operands.pop();
            string expression = "(" + operand1 + postfix[i] + operand2 + ")";
            operands.push(expression);
        } else {
            operands.push(string(1, postfix[i]));
        }
    }

    return operands.top();
}

int main() {
    // string postfix = "3291-*-23+34-*";
    string postfix = "3291-*-23+34-*+"; 
    string infix = postfixToInfix(postfix);
    cout << "Infix Expression: " << infix << endl;

    return 0;
}
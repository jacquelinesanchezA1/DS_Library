#include <iostream>
#include <stack>
#include <string>
using namespace std; 

/* credit : https://leetcode.com/problems/basic-calculator/solutions/62432/ac-c-solution-with-two-stacks/ */

class Calculator {
public:
    int performOperation(int x, int y, char op) {
        switch (op) {
            case '+': return x + y;
            case '-': return x - y;
            case '*': return x * y;
            case '/': 
                if (y == 0) throw runtime_error("division by zero");
                return x / y;
            default: return 0;
        }
    }

    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }

    int calculate(string str) {
        stack<int> resultStack;
        stack<char> operatorStack;

        for (int i = 0; i < str.size(); i++) {
            char c = str[i];
            if (c == ' ') continue;

            if (c == '-' && (i - 1 < 0 || str[i - 1] == '(')) {
                resultStack.push(0);
            }

            if (isdigit(c)) {
                int value = c - '0';
                while (i + 1 < str.size() && isdigit(str[i + 1])) {
                    value = (value * 10) + (str[i + 1] - '0');
                    i++;
                }
                resultStack.push(value);
            } 
            else if (c == '(') {
                operatorStack.push(c);
            } 
            else if (c == ')') {
                while (!operatorStack.empty() && operatorStack.top() != '(') {
                    evaluateTop(resultStack, operatorStack);
                }
                operatorStack.pop();  // remove '('
            } 
            else if (c == '+' || c == '-' || c == '*' || c == '/') {
                while (!operatorStack.empty() && precedence(operatorStack.top()) >= precedence(c)) {
                    evaluateTop(resultStack, operatorStack);
                }
                operatorStack.push(c);
            }
        }

        while (!operatorStack.empty()) {
            evaluateTop(resultStack, operatorStack);
        }

        return resultStack.top();
    }

private:
    void evaluateTop(stack<int>& resultStack, stack<char>& operatorStack) {
        int y = resultStack.top();
        resultStack.pop();
        int x = resultStack.top();
        resultStack.pop();
        char op = operatorStack.top();
        operatorStack.pop();
        resultStack.push(performOperation(x, y, op));
    }
};


int main(){

    calculator stackA; 

    // PEMDAS 
    // 23+3-1*4
    // 23+3-4 
    // 26-4 = 22

    // 23+3-1*5
    // 23+3-5 = 26-5 = 21

    int result1 = stackA.calculate("23+3-1*(2+3)");  // expected: 23+3-5 = 21
    cout<< result1;

    cout<<endl; 

    // correct
    int result2 = stackA.calculate("(5+7)-9");  // expected: 3
    cout<< result2;  

    int result3 = calc.calculate("23+3*4");
    cout << "result 3: " << result3 << endl; // expected: 23 + (3*4) = 35

}

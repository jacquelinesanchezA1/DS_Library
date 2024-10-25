#include <iostream>
#include <stack>
using namespace std; 

/* credit : https://leetcode.com/problems/basic-calculator/solutions/62432/ac-c-solution-with-two-stacks/ */

class calculator{


    public: 

    int performOperation(int x, int y, char op){
        if(op == '+'){
            return x+y; 
        }else{
            return x-y; 
        }
    }



    int calculate(string str){
        stack<int> resultStack; 
        stack<char> operatorStack; 

        for(int i = 0; i<str.size(); i++){
            char c = str[i]; 

            // skip whitespaces
            if(c == ' ') continue; 


            // if handle unary '-' operator
            if(c == '-' && (i-1<0 || str[i-1] == '(')){

                resultStack.push(0); 
            }

            if(c == '*' || c== '/' || c == '+' || c == '-' || c == '('){

            operatorStack.push(c); 
            continue; }



        // pop '('
        if(c == ')') operatorStack.pop(); 

        if(isdigit(c)){
            int value = c-'0'; 
            while(i + 1<str.size() && isdigit(str[i+1])){
                value = (value*10) + (str[i+1] - '0'); 
                i++; 
            }
            resultStack.push(value); 
        }

        if(!operatorStack.empty() && (operatorStack.top() == '+' || operatorStack.top() == '-' || operatorStack.top() == '*' || operatorStack.top() == '/')){
            
            int y = resultStack.top(); 
            resultStack.pop(); 

            int x = resultStack.top(); 
            resultStack.pop(); 

            char op = operatorStack.top(); 
            operatorStack.pop(); 

            int result = performOperation(x, y, op); 
            resultStack.push(result); 
        }
    }

    return resultStack.top(); 
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

    int result1 = stackA.calculate("23+3-1*(2+3)"); 
    cout<< result1;

    cout<<endl; 

    // correct
    int result2 = stackA.calculate("(5+7)-9"); 
    cout<< result2;  

}
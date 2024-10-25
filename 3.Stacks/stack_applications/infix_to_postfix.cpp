#include <iostream>
#include <stack>
using namespace std;

// upload kahoot!
// function that return priority of operator
int checkOperatorPriority(char op){

    if(op == '^'){
        return 3;
    }
    else if(op == '*' || op == '/'){
        return 2; 
    }
    else if(op == '+' || op == '-'){
        return 1; 
    }
    else{
        return -1;
    }
}

// if operator has greater priority vavlue we push 
// if operator is lesser or equal value we pop until top has operator of greater value. 

string infixToPostfix(string str){
    stack <char> s; 
    string postfix = ""; 

    // iterate through string 
    for(int i = 0; i<str.length(); i++){

        // if character is an operand, add to postfix string 
        if(isdigit(str[i])){
            postfix += str[i]; 
        }
        // push opening paranthesis to stack 
        else if(str[i] == '('){
            s.push(str[i]); 
        }

        // when you find a closing paranthesis, pop all operators from stack 
        // until you reach the opening parenthesis 
        else if(str[i] == ')'){
            while(!s.empty() && s.top() != '('){  // until we have not reached the open paranthesis '('
                postfix += s.top(); 
                s.pop(); 
            }
            s.pop(); // we have already reached the open paranthesis! '(' pop it!
        }

        // if you find another operator 
        else{

            while(!s.empty() && checkOperatorPriority(str[i]) <= checkOperatorPriority(s.top())){ // Corrected condition
                postfix += s.top(); 
                s.pop(); 
            }
            s.push(str[i]); // Push current operator onto the stack
        }
    }

    while(!s.empty()){ // delete the remaining operators 
        postfix += s.top(); 
        s.pop(); 
    }
    return postfix; 
}



int main(){

    string infix0 = "23+3/2"; 
    string infix1 = "(24+7)/3"; 
    string infix2 = "4+3-7"; 
    string infix3 = "34-2+3"; 
    string infix4 = "22^3+7"; 

    string postfix0 = infixToPostfix(infix0); 
    string postfix1 = infixToPostfix(infix1); 
    string postfix2 = infixToPostfix(infix2); 
    string postfix3 = infixToPostfix(infix3); 
    string postfix4 = infixToPostfix(infix4); 

    cout<<"The infix: "<<infix0<<" & postfix: "<<postfix0<<endl;
    cout<<"The infix: "<<infix1<<" & postfix: "<<postfix1<<endl; 
    cout<<"The infix: "<<infix2<<" & postfix: "<<postfix2<<endl; 
    cout<<"The infix: "<<infix3<<" & postfix: "<<postfix3<<endl; 
    cout<<"The infix: "<<infix4<<" & postfix: "<<postfix4<<endl; 

}
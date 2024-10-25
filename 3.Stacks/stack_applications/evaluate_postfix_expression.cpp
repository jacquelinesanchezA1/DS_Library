#include <iostream> 
#include <stack> 
#include <string> 
using namespace std; 


int evaluatePostfix(string postfix){

    stack <int> s; 

    for(int i = 0; i<postfix.size(); ++i){

        if(isdigit(postfix[i]))
            s.push(postfix[i] - '0'); 


        else{

            int v1 = s.top(); 
            s.pop(); 

            int v2 = s.top(); 
            s.pop();

            switch(postfix[i]){

                case '+': 
                    s.push(v2 + v1); 
                    break; 

                case '-': 
                    s.push(v2 - v1); 
                    break; 

                case '*': 
                    s.push(v2 * v1); 
                    break; 

                case '/':
                    s.push(v2 / v1); 
                    break; 

                case '^': 
                    s.push(pow(v2, v1)); 
                    break; 
            }
        }

    }
    return s.top(); 
}

int main(){

    string postfix1 = "234*+";  
    string postfix2 = "34*25*+";
    string postfix3 = "45*3-"; 
    string postfix4 = "82/4*"; // 8/24* cause a seg fault error
    string postfix5 = "72+3*"; 
    string postfix6 = "512+4*+3-"; 
    string postfix7 = "93/2+1*"; 
    // string postfix3 = 

    int eva1 = evaluatePostfix(postfix1); 
    int eva2 = evaluatePostfix(postfix2); 
    int eva3 = evaluatePostfix(postfix3); 
    int eva4 = evaluatePostfix(postfix4); 
    int eva5 = evaluatePostfix(postfix5); 
    int eva6 = evaluatePostfix(postfix6); 
    int eva7 = evaluatePostfix(postfix7); 

    cout<<eva1<<endl;
    cout<<eva2<<endl; 
    cout<<eva3<<endl; 
    cout<<eva4<<endl;
    cout<<eva5<<endl; 
    cout<<eva6<<endl; 
    cout<<eva7<<endl;

}
#include <iostream> 
#include <string> 
#include <stack> 
using namespace std; 


bool isValid(string str){

    stack <char> s; 
    
    char open[] = {'(','{', '['}; 
    char close[] = {')', '}', ']'}; 
    int i = 0; 

    while(i<str.length()){

        // (A) If str[i] is Opening paranthesis!

        if(str[i] == open[0] || str[i] == open[1] || str[i] == open[2]){
            s.push(str[i]); 
        }

        // (B) If str[i] is Closing paranthesis!
        else{

            // if the stack is empty!
            if(s.empty()){
                return false; 
            }

            else{

                if(str[i] == close[0] && s.top() == open[0]){
                    s.pop(); 
                }

                else if(str[i] == close[1] && s.top() == open[1]){
                    s.pop(); 
                }

                else if(str[i] == close[2] && s.top() == open[2]){
                    s.pop(); 
                }
                
                else{
                    return false; 
                }
            }
        }
        i++; 
    }

    if(s.empty()){
        return true; 
    }else{
        return false; 
    }

}

int main(){


    string paranthesis0 = "()[{[()]}]"; 
    string paranthesis1 = "()[[[[({})]]]]"; 
    string paranthesis2 = "[([)]"; 

    bool isValid0 = isValid(paranthesis0); 
    bool isValid1 = isValid(paranthesis1);
    bool isValid2 = isValid(paranthesis2); 

    cout<<isValid0<<endl; 
    cout<<isValid1<<endl;
    cout<<isValid2<<endl;  
}
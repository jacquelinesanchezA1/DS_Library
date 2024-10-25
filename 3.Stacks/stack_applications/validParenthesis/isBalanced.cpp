#include <iostream> 
#include <string>
#include <stack> 
using namespace std; 

bool isBalanced(string s){

    stack <char> schar; 
    int i = 0; 
    char open[] = {'(', '{', '['}; 
    char close[] = {')', '}', ']'}; 

    while(schar[i++] != '\0'){

        if(isdigit(s[i]))
            continue; 

        // search for open brackets pos = int seach(0, s[i])
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            schar.push(s[i]); 
        }
        else{   // pos int seach(c, s[i])
                // if pos = pos of open bracket in stack then pop else reuturn false

        }
    }
    if !schar.isempty() 
        return false; 
    return true; 
}
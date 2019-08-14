//Balanced Parenthesis Problem using stack
#include<bits/stdc++.h>
using namespace std;

bool checkBalanced(string str){
    stack<char> s;
    for(int i=0;i<str.length();i++){

        if(str[i] == '{' || str[i] == '(' || str[i] == '['){
            s.push(str[i]);
        }
        else if(str[i] == '}' || str[i] == ')' || str[i] == ']'){
            if(s.empty()){
                return false;
            }
            switch(str[i]){
                case '}':
                    if(s.top() == '{') s.pop();
                    else return false;
                    break;

                case ')':
                    if(s.top() == '(') s.pop();
                    else return false;
                    break;

                case ']':
                    if(s.top() == '[') s.pop();
                    else return false;
                    break;

            }

        }
        //if other chars other than {,(,[
        else
            continue;
    }
    return true;
}


int main(){

    string expr;
    expr = "{[a+b]*c}(c+d)";
    if(checkBalanced(expr))
        cout<<"Balanced";
    else
        cout<<"Not Balanced";
    return 0;
}

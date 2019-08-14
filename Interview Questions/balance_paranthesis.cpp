#include <iostream>
#include<string.h>
using namespace std;

char stack[INT16_MAX];
int top = -1;

void push(char item){
    if(top>=INT16_MAX) cout<<"Stack full"<<endl;
    stack[++top] = item;
}

char pop(){
    if (top == -1) cout<<"Stack empty"<<endl;
    return stack[top--];
}

char stackPeek(){
    if(top == -1) return -1;
    return stack[top];
}

int main(){

    char inp[INT16_MAX];
    cout<<"Enter string to check for balanced Paranthesis: "<<endl;
    cin>>inp;
    
    for(int i=0;i<strlen(inp);i++){
        char cur = inp[i];
        if (cur==')' && stackPeek()=='(')  pop();
        else if (cur==']' && stackPeek()=='[')  pop();
        else if (cur=='}' && stackPeek()=='{')  pop();
        else push(cur);
    }

    if(stackPeek() == -1) cout<<"Balanced"<<endl;
    else cout<<"Not Balanced"<<endl;
    
    return 0;
}


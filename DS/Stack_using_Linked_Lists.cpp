//Stack implementation using linked lists
#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* link;
};

node* head = NULL;

void push(int item){
    node* temp = new node();
    temp -> data = item;
    temp -> link = head;
    head = temp;
}

int pop(){

    //if stack empty return -1
    if(head==NULL)
        return -1;

    node* temp = head;
    int val = temp->data;
    head = temp->link;
    delete temp;

    return val;
}

void printStack(){
    node* it = head;
    while(it != NULL){
        cout<<it->data<<" ";
        it = it->link;
    }
    cout<<"\n";
}

int main(){

    push(5);
    push(4);
    push(3);
    push(2);
    push(1);

    printStack();

    cout<<pop()<<endl;
    cout<<pop()<<endl;
    cout<<pop()<<endl;
    cout<<pop()<<endl;
    cout<<pop()<<endl;

    cout<<pop()<<endl;

    return 0;
}

//Reverse linked list
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head;

//insert at first
void Insert(int item){

    Node* temp = new Node();
    temp->data = item;
    temp->next = head;
    head = temp;
}

void printList(Node* p){
    if(p==NULL){
        cout<<endl;
        return;
    }
    cout<<p->data<<" ";
    printList(p->next);
}

//iterative reverse using temp
void iterativeReverse(){

    //Node *node !Node* a
    Node *prevNode,*curNode,*nextNode;

    curNode = head;
    prevNode = NULL;

    while(curNode != NULL){
        nextNode = curNode->next;
        curNode->next = prevNode;

        prevNode = curNode;
        curNode = nextNode;
    }

    head = prevNode;

}

//reverse using stack
void reverseStack(){
    if(head == NULL)
        return;
    stack<struct Node*> s;

    Node* temp = head;
    while(temp != NULL){
        s.push(temp);
        temp = temp->next;
    }

    temp = s.top();
    head = temp;
    s.pop();

    while(!s.empty()){
        temp->next = s.top();
        s.pop();
        temp = temp->next;
    }
    temp -> next = NULL;

}


int main(){

    head = NULL;

    Insert(5);
    Insert(4);
    Insert(3);
    Insert(2);
    Insert(1);
    printList(head);
    reverseStack();
    printList(head);

    return 0;
}

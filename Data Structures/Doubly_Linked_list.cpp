#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* createNode(int data){
    Node* temp = new Node();
    temp->data = data;
    temp->prev = temp->next = NULL;
    return temp;
}

Node* head;

//insert at head
void InsertAtHead(int item){
    Node* newNode = createNode(item);
    if(head == NULL){
        head = newNode;
        return;
    }

    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

//insert at tail
void InsertAtTail(int item){
    Node* newNode = createNode(item);
    if(head == NULL){
        head = newNode;
        return;
    }

    Node* it = head;
    while (it->next != NULL)
    {
        it = it->next;
    }

    it->next = newNode;

}

void printList(){
    Node* temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}

void printReverseList(){
    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }


    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp -> prev;
    }
    cout<<endl;
}


int main(){

    head = NULL;

    InsertAtHead(5);
    InsertAtHead(4);
    InsertAtHead(3);
    InsertAtHead(2);
    InsertAtHead(1);
    printList();
    InsertAtTail(999);
    printList();


    return 0;
}

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

    //Make node pointed by head as second
    temp->next = head;

    //point head to new Head
    head = temp;
}

//insert at n: 1-indexing
void Insert(int item,int n){
    Node* temp = new Node();
    temp->data = item;
    temp->next = NULL;

    //if location is 1
    if(n==1){
        temp->next = head;
        head = temp;
        return;
    }

    Node* it = head;
    for(int i=0;i<n-2;i++)
        it = it->next;

    temp -> next = it->next;
    it->next = temp;
}

//delete node at n(1 indexing)
void deleteNode(int n){
    Node* temp1 = head;

    if(n==1){
        head = temp1->next;
        delete temp1;
        return;
    }

    for(int i=0;i<n-2;i++)
        temp1 = temp1->next;

    Node* temp2 = temp1->next;
    //temp1 : (n-1)th node , temp2 = nth node
    temp1 -> next = temp2->next;
    delete temp2;
}

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

//recursive print
void printList(Node* p){
    if(p==NULL){
        cout<<endl;
        return;
    }
    cout<<p->data<<" ";
    printList(p->next);
}

//recursive reverse print
void printReverse(Node* p){
    if(p==NULL){
        return;
    }
    printReverse(p->next);
    cout<<p->data<<" ";
}

void recursiveReverse(Node* p){
    if(p->next == NULL){
        head = p;
        return;
    }
    recursiveReverse(p->next);

    Node* q = p -> next;
    q -> next = p;
    p -> next = NULL;


}

void IterativePrintList(){
    Node* temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}


int main(){

    head = NULL;

    Insert(5);
    Insert(4);
    Insert(3);
    Insert(2);
    Insert(1);
    recursiveReverse(head);
    printList(head);

//    iterativeReverse();
//    printList();

    return 0;
}

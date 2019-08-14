
#include <iostream>
#define ll long long 
using namespace std; 
  
struct node {
    int data;
    node* next;
};

// a--> b is same as (*a).b 

void insertBeginning(node** head,int value){
    node* temp = new node();
    temp->next = NULL;
    temp->data = value;
    if (*head!=NULL) temp->next = *head;
    *head = temp;
}

void insertLast(node** head,int value){
    node* cur = *head;
    node* prev;

    node* temp = new node();
    temp->data = value;
    temp->next = NULL;

    if (*head == NULL){
        *head =temp;
        return;
    }

    while (cur != NULL){
        prev = cur;
        cur = cur->next;
    }
    prev->next = temp;
    
}

void insertPos(node** head,int value,int pos){
    node* temp = new node();
    temp->data = value;
    temp->next = NULL;

    if(pos==1){
        temp->next = *head;
        *head = temp;
        return;
    }

    node* cur = *head;
    for(int i=0;i<pos-2;i++){
        cur = cur->next;
    }

    temp->next = cur->next;
    cur->next = temp;
}

void deletePos(node** head,int n){
    node* cur = *head;
    for(int i=0;i<n-2;i++){
        cur = cur->next;
    }


}

void printList(node** head){
    node* temp= *head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void printRecursive(node* p){
    
    if (p == NULL){
        return;
    }
    cout<<p->data<<" ";
    printRecursive(p->next);

}

void reverseListIterative(node** head){
    node* prev;
    node* next;
    node* cur= *head;
    prev =  NULL;
    while(cur!=NULL){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *head = prev;
}

void reverseRecursive(node** head,node* p){
    if (p->next == NULL){
        *head = p;
        return;
    }

    reverseRecursive(head,p->next);

    node* q = p->next;
    q->next = p;
    p->next = NULL;

}

int main() 
{ 
    cout<<"Code Started"<<endl;
    node* head = NULL;

    insertLast(&head,1);
    insertLast(&head,2);
    insertLast(&head,3);
    printRecursive(head);
    reverseRecursive(&head,head);
    // printRecursive(head);
    return 0;
} 


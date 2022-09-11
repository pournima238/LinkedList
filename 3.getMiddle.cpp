#include<bits/stdc++.h>
using namespace std;
 class Node 
        { 
        public:
            int data;
            Node *next;
            Node(int data) 
            {
               this->data = data;
              this->next = NULL;
            }
        };

int getLength(Node* & head){
    Node * temp=head;
    int length=0;
    while(temp!=NULL){
        length++;
        temp=temp->next;
    }
    return length;
}

Node *findMiddle(Node* head) {
    int length= getLength(head);
    int cnt=0;
    Node *temp=head;
    while(cnt<length/2)
    {
        temp=temp->next;
        cnt++;
    }    
    return temp;
    
}
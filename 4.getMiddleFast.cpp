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



//Another approach
Node* getAnswer(Node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* fast=head->next;
    Node* slow=head;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
          fast=fast->next;  
        }
        slow=slow->next;
    }
    return slow;
}
Node *findMiddle(Node* head) {

    Node* ans=getAnswer(head);
    return ans;
    
}
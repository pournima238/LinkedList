#include <bits/stdc++.h>
using namespace std;
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

Node<int>* solve(Node<int>* head1,Node<int>* head2){
        if(head1->next==NULL){
            head1->next=head2;
            return head1;
        }
       Node<int>* curr1=head1->next;
       Node<int>* curr2=head2;
        Node<int>* prev1=head1;
        Node<int>* next2=NULL;
        while(curr1!=NULL && curr2!=NULL){
           if((curr2->data >=prev1->data) && (curr2->data<= curr1->data)){
               prev1->next=curr2;
               next2=curr2->next;
               curr2->next=curr1;
               prev1=curr2;
               curr2=next2;
           }else{
               prev1=curr1;
               curr1=curr1->next;
               if(curr1->next==NULL){
                   curr1->next=curr2;
                   return head1;
               }
           }
        }
        return head1;
        
    }

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{  //first list is empty
    if(first==NULL){
        return second;
    }
    //second list is empty
    if(second==NULL){
        return first;
    }
    //if a first value in second list is bigger than the first element in first element
    if(first->data<=second->data){
        return solve(first, second);
    }else{
        return solve(second, first);
    }
}

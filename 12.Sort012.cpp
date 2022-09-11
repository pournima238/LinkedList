//there are two approaches in this solution.
#include <bits/stdc++.h>
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



void populate (Node* &tail, int data){
    Node * newNode= new Node(data);
    tail->next=newNode;
    tail=newNode;
}
//second approach make three list of one, two and zero and then merge
void solve(Node* &head){
    //first make dummy nodes
    Node* zero_head=new Node(-1);
    Node* zero_tail=zero_head;
     Node* one_head=new Node(-1);
     Node* one_tail=one_head;
     Node* two_head=new Node(-1);
     Node* two_tail=two_head;
    
    //now we traverse and populate
   Node* temp=head;
    while(temp!=NULL){
        if(temp->data==0){
            populate(zero_tail,temp->data);
        }else if(temp->data==1){
            populate(one_tail,temp->data);
        }else{
            populate(two_tail, temp->data);
        }
        temp=temp->next;
    }
    //merge three lists
    if(one_tail!=NULL){
        zero_tail->next=one_head->next;
    }else{
        zero_tail->next=two_head->next;
    }
    one_tail->next=two_head->next;
    head=zero_head->next;
    //delete dummy nodes;
    delete zero_head;
    delete one_head;
    delete two_head;
    
    
    
}

Node* sortList(Node *head)
{
//    //first approach=> take a count and replace;
//     int zero_cnt=0;
//     int one_cnt=0;
//     int two_cnt=0;
//     Node* temp=head;
//     //traverse to count
//     while(temp!=NULL){
//         if(temp->data==0){
//             zero_cnt++;
//         }else if(temp->data==1){
//             one_cnt++;
//         }else{
//             two_cnt++;
//         }
//         temp=temp->next;
//     }
//     //traverse to replace
//     temp=head;
//     while(temp!=NULL){
//        if(zero_cnt!=0){
//            temp->data=0;
//            zero_cnt--;
//        }else if(one_cnt!=0){
//            temp->data=1;
//            one_cnt--;
//        }else if(two_cnt!=0){
//      temp->data=2; 
//            two_cnt--;
//        }
//         temp=temp->next;
//     }
solve(head);
return head;
}

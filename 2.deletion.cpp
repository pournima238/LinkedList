//single linked list
//all deletion operations

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node * next;

    node(int data){
        this->data=data;
        this->next=NULL;
    }

    ~node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"the element deleted is"<<value<<endl;
    }


};
void print(node* &head){
    //taking head by reference as do not want to create copy
    //for printing we will make temp ptr which will move accross all nodes

    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
}

void deleteFirstNode(node *&head){
    node * temp=head;
    head=head->next;
    temp->next=NULL;
    delete temp;

}
void deletePosNode(node *& head, int pos, node*& tail){
    if(pos==1){
        deleteFirstNode(head);
        return;
    }else{
    node* cur=head;
    node* prev=NULL;
    int cnt=1;
    while(cnt<pos){
        prev=cur;
        cur=cur->next;
        cnt++;
    }
    prev->next=cur->next;
    if(cur->next==NULL){
        tail=prev;
    }
    cur->next=NULL;
    delete cur;
}
    

}


int main(){
      //creating all nodes
    node * node1=new node(10);
    node * node2= new node(20);
    node * node3= new node(30);
    node * node4= new node(40);
    //creating head node and pointing it to first node
    node * head=node1;
//creating links between nodes
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    //tail node
    node* tail=node4;

    //deleting first node
    print(head);
    cout<<endl;
//    deleteFirstNode(head);
//     print(head);
//     cout<<endl;

    //for deleting last and middle node we require prev node and current node so same code can be used
    deletePosNode(head,2, tail);
    print(head);
    cout<<endl;
    

}
//single linked list all insertion operations
//node creation as well

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    //contructor
    node(int data){
        this->data=data;
        this->next=NULL;
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
bool isCircular(node* tail){
    if(tail==NULL){
        return 1;
    }
    node* temp=tail->next;
    while(temp!=NULL && temp!=tail){
        temp=temp->next;
    }
    if(temp==tail){
        return 1;
    }
    if(temp==NULL){
        return 0;
    }
}
void InserAtHead( node* &head, int data){

    //creating new node
    node *newNode= new node(data);
    //pointing newnode pointer to heads pointer
    newNode->next=head;
    //pointing head at newNode
    head=newNode;

}
void InsertAtTail(node * &tail, int data){
    //create new node
    node * newNode=new node(data);
    //pointing tail node to newnode
    tail->next=newNode;
    //making new node tail
    tail=newNode;


}
void InsertAtPosition(node * &head,node *&tail, int pos, int data){


    //now remeber inserting at head does not work by inserting at position so we write condition 
    //beacause our cnt starts from 1
    if(pos==1){
        InserAtHead(head,data);
        return;
    }
    
    //intializing cnt to 1
    int cnt=1;
    //to insert at that position we must bring our pointer to previous node of position
    node *temp=head;
    while(cnt<pos-1){
        temp=temp->next;
        cnt++;

    }
    //even we cannot  add at tail using this function because tail is not updated 
    //even though we can add at end
    //so we will check if we are at en node then call funct
    if(temp->next==NULL){
        InsertAtTail(tail,data);
        return;
           
            }
    //create new node
    node * newNode=new node(data);

    //adjust links now
    newNode->next=temp->next;
    temp->next=newNode;


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

    //calling function to print out linked list
    cout<<"Normal LInked list"<<endl;
    print(head);
    cout<<endl;

    //inserting node at head
    cout<<"Linked list after adding at head"<<endl;
    InserAtHead(head,90);
    InserAtHead(head,80);

    print(head);
    cout<<endl;

//inserting at tail
cout<<"Linked list after adding at tail"<<endl;
node *tail=node4;
InsertAtTail(tail,50);
InsertAtTail(tail,60);

print(head);
cout<<endl;
//insert at position
cout<<"Linked list after adding at position"<<endl;
InsertAtPosition(head,tail, 9, 78);
print(head);
cout<<endl;
 if(isCircular(head)){
        cout<<"circular in nature"<<endl;
    }else{
        cout<<"not circular in nature"<<endl;
    }



     

   

    

}
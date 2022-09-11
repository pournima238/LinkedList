#include<bits/stdc++.h>
using namespace std;

////declaring node
class node{
    public: 
    int data;
    node* next;

    node(int data){
        this->data=data;
        this->next=NULL;
    }

    ~node(){
        int value=this->data;
        if(this->next !=NULL){
           delete next;
           next=NULL; 


        }
        cout<<"the data"<<value<<"is deleted"<<endl;
    }

};
//////insert function

void insertNode( node* &tail, int element, int data){

   
    //if list is empty
    if(tail==NULL){
        node* newNode= new node(data);
        tail=newNode;
        //circular link
        newNode->next=newNode;

    }else{
         node* curr=tail;
        //not an empty list
      while(curr->data!=element){
          curr=curr->next;
      }
        node* temp1 = new node(data);
        temp1-> next = curr -> next;
        curr -> next = temp1;
    }
}
////deletion function( Very Very important revise..)
void deleteNode(node* &tail, int value){
    if(tail==NULL){
        cout<<"The list is empty please check again"<<endl;
        return;
    }
    node* prev=tail;
    node* curr=prev->next;
    while(curr->data !=value){
        prev=curr;
        curr=curr->next;
    }
    prev->next=curr->next;

    if(prev==curr){
        tail=NULL;
    }
    if(tail==curr){
        tail=prev;
    }
    curr->next=NULL;
    delete curr;

}
/////print function
void print(node* tail){
if(tail==NULL){
    cout<<"THe list is empty"<<endl;
}else{
    node* temp=tail;
    node* curr=tail;

    do{
        cout<<curr->data<<endl;
        curr=curr->next;
    }while(curr!=temp);
    
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

bool isLoop(node* tail){
    if(tail==NULL){
        return true;
    }
    map<node*, int> visited;
    node*temp=tail;
    while(visited[temp]!=1 && temp!=NULL){
        visited[temp]=1;
        temp=temp->next;
    }
    if(temp==NULL){
        return false;
    }else{
        return true;
    }

}


int main(){
    node* tail=NULL;
    insertNode(tail,1,10);
    insertNode(tail,10,20);
    insertNode(tail,20,30);
    print(tail);

    deleteNode(tail,20);
    print(tail);
    if(isLoop(tail)){
        cout<<"circular in nature"<<endl;
    }else{
        cout<<"not circular in nature"<<endl;
    }
    

    //there are three cases in here that list is empty
    //case1= empty list
    //case2= one node only present linking to itself
    //case3=>normal list
    //point to be noted
    //no head only tail


}
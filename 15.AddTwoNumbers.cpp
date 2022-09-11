/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.*/

#include <bits/stdc++.h>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
private:
    void insertAtTail(ListNode* &HeadAns, ListNode* &TailAns, int data){
        ListNode* temp=new ListNode(data);
        if(HeadAns==NULL ){
           HeadAns=temp;
           TailAns=temp; 
            return;
        }else{
            TailAns->next=temp;
            TailAns=temp;
        }
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode* temp1=l1;
       ListNode* temp2=l2;
       ListNode *HeadAns=NULL;
       ListNode *TailAns=NULL;
        int carry=0;
       while(temp1!=NULL && temp2!=NULL){
           int sum=temp1->val+temp2->val+carry;
           int digit=sum%10;
           insertAtTail(HeadAns,TailAns,digit);
           carry=sum/10;
           temp1=temp1->next;
           temp2=temp2->next;
       }
        while(temp1!=NULL){
            int sum=carry+temp1->val;
            int digit=sum%10;
            insertAtTail(HeadAns, TailAns,digit);
            carry=sum/10;
            temp1=temp1->next;   
        }
         while(temp2!=NULL){
            int sum=temp2->val+carry;
            int digit=sum%10;
            insertAtTail(HeadAns, TailAns,digit);
            carry=sum/10;
            temp2=temp2->next;   
        }
        while(carry!=0){
            int sum=carry;
            int digit=sum%10;
            insertAtTail(HeadAns, TailAns,digit);
            carry=carry/10;
        }
        return HeadAns;
    }
};
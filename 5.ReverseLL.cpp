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

// approach2
Node *reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *chotaHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return chotaHead;
}
// approach1 iterative to recursive
Node *solve(Node *curr, Node *prev, Node *forward)
{
    if (curr == NULL)
    {
        return prev;
    }
    forward = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forward;
    solve(curr, prev, forward);
}

Node *reverseLinkedList(Node *head)
{
    //     Node *prev=NULL;
    //     Node *curr=head;

    //     Node* forward;
    //     Node* answer=solve(curr, prev,forward);
    //     return answer;
    return reverse(head);
    //     while(curr !=NULL){
    //         forward=curr->next;
    //         curr->next=prev;
    //         prev=curr;
    //         curr=forward;
    //     }

    //     return prev;
}

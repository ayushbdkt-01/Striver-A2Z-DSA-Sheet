#include<bits/stdc++.h>
using namespace std;



struct Node{
    int data;
    Node* next;
    Node(int d){
        data=d;
        next=NULL;
    }
    Node(int d,Node* nex){
        data=d;
        next=nex;
    }
};



Node* arrayToLinkedList(vector<int> arr){
    Node* head=new Node(arr[0]);
    Node* temp=head;
    for(int i=1;i<arr.size();i++){
        Node* newNode=new Node(arr[i]);
        temp->next=newNode;
        temp=newNode;
    }
    return head;
}



void print(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}


void brute(Node* &head){
    // use stack to reverse data of LL.
    Node* temp=head;
    stack<int> s;
    while(temp!=NULL){
        s.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        temp->data=s.top();
        s.pop();
        temp=temp->next;
    }
}



void optimal(Node* &head){
    Node* prev=NULL;
    Node* temp=head;
    while(temp!=NULL){
        Node* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    head=prev;
}



Node* reverseRecursion(Node* &head){
    if(head==NULL || head->next==NULL) return head;
    Node* newHead=reverseRecursion(head->next);
    Node* front=head->next;
    front->next=head;
    head->next=NULL;
    return newHead;
}



int main(){
    vector<int> arr={10,23,21,22,34,56,76};
    Node* head=arrayToLinkedList(arr);
    brute(head);
    print(head);
    optimal(head);
    print(head);
    head=reverseRecursion(head);
    print(head);
    return 0;
}
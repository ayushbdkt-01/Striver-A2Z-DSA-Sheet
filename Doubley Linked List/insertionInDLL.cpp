#include<bits/stdc++.h>
using namespace std;



struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int d){
        data=d;
        next=NULL;
        prev=NULL;
    }
};



Node* arrayToLinkedList(vector<int> arr){
    Node* head=new Node(arr[0]);
    Node* temp=head;
    for(int i=1;i<arr.size();i++){
        Node* newNode=new Node(arr[i]);
        temp->next=newNode;
        newNode->prev=temp;
        temp=newNode;
    }
    return head;
}



void traverse(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}



void insertHead(Node* &head,int value){
    if(head==NULL) {
        Node* newNode=new Node(value);
        return;
    }
    Node* newNode=new Node(value);
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
}



void insertTail(Node* &head,int value){
    if(head==NULL) {
        Node* newNode=new Node(value);
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* newNode=new Node(value);
    temp->next=newNode;
}



int main(){
    vector<int> arr={10,23,21,22,34,56,76};
    Node* head=arrayToLinkedList(arr);
    cout<<"Before Insertion: ";
    traverse(head);
    cout<<"After Insertion: ";
    insertHead(head,1000);
    traverse(head);
    insertTail(head,1000);
    cout<<"After Insertion: ";
    traverse(head);
    return 0;
}
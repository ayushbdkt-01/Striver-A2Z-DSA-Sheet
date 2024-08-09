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



void reverse(Node* &head){
    if(head==NULL || head->next==NULL) return;
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



void addOne(Node* &head){
    int carry=1;
    Node* temp=head;
    while(temp!=NULL){
        temp->data=temp->data+carry;
        if(temp->data>=10){
            temp->data=0;
            carry=1;
        }
        else{
            carry=0;
            break;
        }
        temp=temp->next;
    }
    reverse(head);
    if(carry==1){
        Node* newNode=new Node(1);
        newNode->next=head;
        head=newNode;
    }
}



void traverse(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}



int recursion(Node* &head){
    if(head==NULL) return 1;
    int carry=recursion(head->next);
    head->data=head->data+carry;
    if(head->data<10) return 0;
    else{
        head->data=0;
        return 1;
    }
}



int main(){
    vector<int> arr={9,9,9,9};
    Node* head=arrayToLinkedList(arr);
    reverse(head);
    addOne(head);
    traverse(head);

    Node* temp=head;
    int carry=recursion(temp);
    if(carry==1){
        Node* newNode=new Node(1);
        newNode->next=head;
        head=newNode;
    }
    traverse(head);


    return 0;
}
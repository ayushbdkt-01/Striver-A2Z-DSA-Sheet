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
    if(head==NULL || head->next==NULL) return;
    vector<int> arr;
    Node* temp=head;

    while(temp!=NULL && temp->next!=NULL){
        arr.push_back(temp->data);
        temp=temp->next->next;
    }
    if(temp!=NULL) arr.push_back(temp->data);

    temp=head->next;
    while(temp!=NULL  && temp->next!=NULL){
        arr.push_back(temp->data);
        temp=temp->next->next;
    }
    if(temp!=NULL) arr.push_back(temp->data);

    
    temp=head;
    for(int i=0;i<arr.size();i++){
        temp->data=arr[i];
        temp=temp->next;
    }
}



void optimal(Node* &head){
    if(head==NULL || head->next==NULL) return;
    Node* oddHead=head;
    Node* evenHead=head->next;
    Node* oddTemp=oddHead;
    Node* evenTemp=evenHead;
    while(evenTemp!=NULL && evenTemp->next!=NULL){
        oddTemp->next=oddTemp->next->next;
        oddTemp=oddTemp->next;
        evenTemp->next=evenTemp->next->next;
        evenTemp=evenTemp->next;
    }
    oddTemp->next=evenHead;
}



int main(){
    vector<int> arr={1,2,3,4,5,6,7,8,9};
    Node* head=arrayToLinkedList(arr);
    optimal(head);
    print(head);
    return 0;
}
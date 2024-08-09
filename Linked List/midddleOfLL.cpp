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




void traverse(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}


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


void brute(Node* &head){
    int length=0;
    Node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        length++;
    }
    int middleIndex=(length/2)+1;
    temp=head;
    while(temp!=NULL){
        middleIndex--;
        if(middleIndex==0){
            cout<<"Middle node is: "<<temp->data<<endl;
            return;
        }
        temp=temp->next;
    }
    cout<<"No middle node"<<endl;
}


void optimal(Node*&head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<"Middle node is: "<<slow->data<<endl;
}



int main(){
    vector<int> arr={10,23,21};
    Node* head=arrayToLinkedList(arr);
    brute(head);
    optimal(head);
    return 0;
}
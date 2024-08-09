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


void brute(Node* &head,int n){
    // find the length of LL and delete the (length-k)th node from front.
    int length=0;
    Node* temp=head;
    while(temp!=NULL){
        length++;
        temp=temp->next;
    }
    if(n==length){ // delete first element.
        head=head->next;
        return;
    }
    int indexToDelete=length-n;
    temp=head;
    Node* prev=NULL;
    int count=0;
    while(temp!=NULL){
        if(count==indexToDelete) break;
        count++;
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    temp->next=NULL;
    delete temp;
}



void optimal(Node* &head,int n){
    Node* slow=head;
    Node* fast=head;
    for(int i=0;i<=n;i++) {
        if(fast==NULL){
            return;
        }
        fast=fast->next;
    }

    if(fast==NULL){
            head=head->next;
            return;
        }
    
    while(fast!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    Node* NodeToDelete=slow->next;
    slow->next=slow->next->next;
    NodeToDelete->next=NULL;
    delete NodeToDelete;
}


int main(){
    vector<int> arr={10,23,21,22,34,56,76};
    Node* head=arrayToLinkedList(arr);
    optimal(head,1);
    print(head);
    return 0;
}
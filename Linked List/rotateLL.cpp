#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int d){
        data=d;
        next=NULL;
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



void optimal(Node* &head,int k){
    Node* tail=head;
    int length=1;
    while(tail->next!=NULL){
        tail=tail->next;
        length++;
    } 
    k=k%length;
    if(k==0) return;
    tail->next=head;
    Node* temp=head;
    int count=length-k;
    temp=head;
    while(temp!=NULL){
        if(count==1){
            head=temp->next;
            temp->next=NULL;
            return;
        }
        count--;
        temp=temp->next;
    }
    cout<<"Code nhi chalra"<<endl;
}


int main(){
    vector<int> arr={1,2,3,4,5};
    Node* head=arrayToLinkedList(arr);
    optimal(head,2);
    traverse(head);

    return 0;
}
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


void brute(Node* &head){
    if(head==NULL || head->next==NULL) return;
    int count0=0;
    int count1=0;
    int count2=0;
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==0) count0++;
        else if(temp->data==1) count1++;
        else count2++;
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        if(count0>0) {
            temp->data=0;
            count0--;
        }
        else if(count1>0) {
            temp->data=1;
            count1--;
        }
        else if(count2>0) {
            temp->data=2;
            count2--;
        }
        temp=temp->next;
    }
}



void optimal(Node* &head){
    Node* zeroHead=new Node(-1);
    Node* oneHead=new Node(-1);
    Node* twoHead=new Node(-1);

    Node* zeroTemp=zeroHead;
    Node* oneTemp=oneHead; 
    Node* twoTemp=twoHead;

    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==0){
            zeroTemp->next=temp;
            zeroTemp=temp;
        }
        else if(temp->data==1){
            oneTemp->next=temp;
            oneTemp=temp;
        }
        else{
            twoTemp->next=temp;
            twoTemp=temp;
        }
        temp=temp->next;
    }
    if(oneHead!=NULL){
        zeroTemp->next=oneHead->next;
    }
    else{
        zeroTemp->next=twoHead->next;
    }
    oneTemp->next=twoHead->next;
    twoTemp->next=NULL;
    head=zeroHead->next;
}



void print(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}



int main(){
    vector<int> arr={1,2,0,0,1,2,2,1,0,0};
    Node* head=arrayToLinkedList(arr);
    optimal(head);
    print(head);
    return 0;
}
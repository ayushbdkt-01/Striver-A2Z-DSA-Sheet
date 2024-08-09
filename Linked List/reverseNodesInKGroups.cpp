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



void reverse(Node* &head){
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



Node* findKthNode(Node* &head,int k){
    Node* temp=head;
    k--;
    while(temp!=NULL && k>0){
        k--;
        temp=temp->next;
    }
    return temp;
}




Node* reverseKGroups(Node* head,int k){
    if(head==NULL || head->next==NULL) return head;
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        Node* kthNode=findKthNode(temp,k);
        if(kthNode==NULL){
            if(prev!=NULL) prev->next=temp;
            break;
        }
        Node* nextNode=kthNode->next;
        kthNode->next=NULL;
        reverse(temp);
        if(prev==NULL) head=kthNode;
        else prev->next=kthNode;
        prev=temp;
        temp=nextNode;
    }
    return head;
}



int main(){
    vector<int> arr={1,2,3,4,5,6,7,8,9,10};
    Node* head=arrayToLinkedList(arr);
    head=reverseKGroups(head,3);
    print(head);
    return 0;
}
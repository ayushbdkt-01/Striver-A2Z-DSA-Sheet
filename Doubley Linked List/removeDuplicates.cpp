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
    }
}


void striverApproach(Node*&head){
    Node* temp=head;
    while(temp!=NULL && temp->next!=NULL){
        Node* nextNode=temp->next;
        while(nextNode!=NULL && nextNode->data==temp->data){
            Node* duplicateNode=nextNode;
            nextNode=nextNode->next;
            delete duplicateNode;
        }
        temp->next=nextNode;
        if(nextNode!=NULL) nextNode->prev=temp;
        temp=temp->next;
    }  
}



void myApproach(Node*&head){
    Node* temp=head;
    while(temp!=NULL){
        if(temp->next!=NULL && temp->data==temp->next->data){
            Node* nodeToDelete=temp->next;
            temp->next=nodeToDelete->next;
            if(nodeToDelete->next!=NULL)nodeToDelete->next->prev=temp;
            nodeToDelete->next=NULL;
            nodeToDelete->prev=NULL;
            delete nodeToDelete;
        }
        else temp=temp->next;
    }
}



int main(){
    vector<int> arr={0,1,1,1,4,5,6,7,7,7};
    Node* head=arrayToLinkedList(arr);
    // striverApproach(head);
    // traverse(head);
    striverApproach(head);
    traverse(head);
    return 0;
}
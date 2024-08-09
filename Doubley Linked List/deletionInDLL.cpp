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



void deleteHead(Node* &head){
    if(head==NULL) return;
    if(head->next==NULL){
        delete head;
        return;
    }
    Node* temp=head;
    head=head->next;
    head->prev=NULL;
    temp->prev=NULL,temp->next=NULL;
    delete(temp);
}



void deleteTail(Node* &head){
    if(head==NULL) return;
    if(head->next==NULL){
        delete head;
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL) temp=temp->next;
    Node* secondLastNode=temp->prev;
    secondLastNode->next=NULL;
    temp->prev=NULL,temp->next=NULL;
    delete temp;
}


void deleteKthElement(Node* &head,int k){
    if(head==NULL) return;
    int count=1;
    Node* temp=head;
    while(temp!=NULL){
        if(count==k) break;
        count++;
        temp=temp->next;
    }
    Node* previousNode=temp->prev;
    Node* nextNode=temp->next;
    if(previousNode==NULL && nextNode==NULL){ // single node
        delete temp;
        return;
    }
    else if(previousNode==NULL){ // first node
        Node* toDelete=head;
        head=head->next;
        toDelete->prev=NULL;
        toDelete->next=NULL;
        delete toDelete;
        return;
    }
    else if(nextNode==NULL){ // Last Node
        previousNode->next=NULL;
        temp->prev=NULL,temp->next=NULL;
        delete temp;
        return;
    }
    else{
        previousNode->next=nextNode;
        nextNode->prev=previousNode;
        temp->next=NULL,temp->prev=NULL;
        delete temp;
        return;
    }
}



int main(){
    vector<int> arr={10,23,21,22,34,56,76};
    Node* head=arrayToLinkedList(arr);
    cout<<"Before Deletion: ";
    traverse(head);
    cout<<"After Deletion: ";
    deleteHead(head);
    traverse(head);
    deleteTail(head);
    cout<<"After Deletion: ";
    traverse(head);
    deleteKthElement(head,5);
    cout<<"After Deletion: ";
    traverse(head);
    return 0;
}
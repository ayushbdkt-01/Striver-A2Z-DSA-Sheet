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



void traversal(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}



void insertHead(Node* &head,int value){
    if(head==NULL){
        Node* newNode=new Node(value);
        return;
    }
    Node* temp=new Node(value);
    temp->next=head;
    head=temp;
}



void insertTail(Node* &head,int value){
    if(head==NULL){
        Node* newNode=new Node(value);
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL) temp=temp->next;
    Node* newNode=new Node(value);
    temp->next=newNode;
}



void insertAtPosition(Node* &head,int position,int value){
    if(head==NULL){
        if(position==1){
            Node* newNode=new Node(value);
            return;
        }else{
            cout<<"Invalid position"<<endl;
            return;
        }
    }
    Node* temp=head;
    int count=2;
    while(temp!=NULL){
        if(count==position){
            Node* newNode=new Node(value);
            newNode->next=temp->next;
            temp->next=newNode;
            return;
        }
        count++;
        temp=temp->next;
    }
    cout<<"Invalid Position"<<endl;
}



int main(){
    vector<int> arr={10,23,21,22,34,56,76};
    Node* head=arrayToLinkedList(arr);
    cout<<"Before Insertion: ";
    traversal(head);
    insertHead(head,100);
    cout<<"After Insertion: ";
    traversal(head);
    insertTail(head,100);
    cout<<"After Insertion: ";
    traversal(head);
    insertAtPosition(head,5,100);
    cout<<"After Insertion: ";
    traversal(head);


    return 0;
}
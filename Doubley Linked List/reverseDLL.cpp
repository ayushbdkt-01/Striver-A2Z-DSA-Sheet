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


void brute(Node* &head){
    // traverse the DLL and insert values in the stack. Make temp=head and again traverse the DLL by inserting top of stack in node and popping the top;
    stack<int> st;
    Node* temp=head;
    while(temp!=NULL){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }
}


void better(Node* &head){
    // seap the data of startNode and endNode. Then start++ and end--;
    Node* startNode=head;
    Node* endNode=head;
    while(endNode->next!=NULL) endNode=endNode->next;
    while(startNode!=endNode){
        swap(startNode->data,endNode->data);
        startNode=startNode->next;
        endNode=endNode->prev;
    }
}



void optimal(Node* &head){
    // by changing the prev and next pointers of each node;
    if(head==NULL || head->next==NULL) return;
    Node* temp=head;
    Node* prev=NULL; 
    while(temp!=NULL){
        temp->prev=temp->next;
        temp->next=prev;
        prev=temp;
        temp=temp->prev;
    }
    head=prev;
}



int main(){
    vector<int> arr={10,23,21,22,34,56,76};
    Node* head=arrayToLinkedList(arr);
    brute(head);
    cout<<"Reversed DLL: ";
    traverse(head);
    better(head);
    cout<<"Reversed DLL: ";
    traverse(head);
    optimal(head);
    cout<<"Reversed DLL: ";
    traverse(head);

    return 0;
}
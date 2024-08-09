#include<bits/stdc++.h>
using namespace std;



struct Node{
    int data;
    Node* next;
    Node* back;
    Node(int d){
        data=d;
        next=NULL;
        back=NULL;
    }
};



Node* arrayToLinkedList(vector<int> arr){
    Node* head=new Node(arr[0]);
    Node* temp=head;
    for(int i=1;i<arr.size();i++){
        Node* newNode=new Node(arr[i]);
        temp->next=newNode;
        newNode->back=temp;
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




void optimal(Node* &head,int target){
    if(head==NULL) return;
    while(head!=NULL && head->data==target) head=head->next;
    if(head==NULL) return;
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        if(temp->data==target){
            Node* nodeToDelete=temp;
            temp=temp->next;
            if(prev!=NULL) prev->next=temp;
            if(temp!=NULL) temp->back=prev;
            nodeToDelete->next=NULL;
            nodeToDelete->back=NULL;
            delete nodeToDelete;
        }
        else {
            prev=temp;
            temp=temp->next;
        }
    }
}



int main(){
    vector<int> arr={10,20,10,13,101,10};
    Node* head=arrayToLinkedList(arr);
    optimal(head,10);
    cout<<"Modified DLL: ";
    traverse(head);

    return 0;
}
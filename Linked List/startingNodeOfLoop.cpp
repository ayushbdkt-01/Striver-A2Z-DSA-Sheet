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
    unordered_map<Node*,int> m;
    Node* temp=head;
    while(temp!=NULL){
        if(m.find(temp)!=m.end()){
            cout<<"Starting Node of Loop is: "<<temp->data<<endl;
            return;
        }
        m[temp]=temp->data;
        temp=temp->next;
    }
    cout<<"Loop is not present"<<endl;
}


void optimal(Node*&head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            slow=head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            cout<<"Starting Node of Loop is: "<<slow->data<<endl;
            return;
        }
    }
    cout<<"Loop is not present"<<endl;
}




int main(){
    vector<int> arr={1,2,3,4,5,6,7};
    Node* head=arrayToLinkedList(arr);
    
    // creating a loop in Linked List.
    Node* temp=head;
    while(temp->next!=NULL) temp=temp->next;
    temp->next=head->next->next;

    brute(head);
    optimal(head);
    return 0;
}
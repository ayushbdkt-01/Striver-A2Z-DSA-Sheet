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
    int timer=1;
    while(temp!=NULL){
        if(m.find(temp)!=m.end()){
            int length=timer-m[temp];
            cout<<"Length of loop is: "<<length<<endl;
            return;
        }
        m[temp]=timer;
        timer++;
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
            int count=1;
            fast=fast->next;
            while(slow!=fast){
                fast=fast->next;
                count++;
            }
            cout<<"Length of loop is: "<<count<<endl;
            return;
        }
    }
    cout<<"Loop is not present"<<endl;
}




int main(){
    // a loop is always present.
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
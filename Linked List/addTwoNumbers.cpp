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



int add(Node* head1,Node* head2){
    Node* temp1=head1;
    Node* temp2=head2;
    Node* dummyNode=new Node(-1);
    Node* curr=dummyNode;
    int carry=0;
    while(temp1!=NULL || temp2!=NULL){
        int sum=carry;
        if(temp1!=NULL) sum += temp1->data;
        if(temp2!=NULL) sum += temp2->data;
        Node* newNode=new Node(sum%10);
        curr->next=newNode;
        curr=newNode;
        carry=sum/10;
        if(temp1!=NULL) temp1=temp1->next;
        if(temp2!=NULL) temp2=temp2->next;
    }
    if(carry!=0){
        Node* newNode=new Node(carry);
        curr->next=newNode;
        curr=newNode;
    }
    Node* ansHead=dummyNode->next;
    while(ansHead!=NULL){
        cout<<ansHead->data<<" ";
        ansHead=ansHead->next;
    }cout<<endl;
}



int main(){
    vector<int> arr1={2,4,3};
    Node* head1=arrayToLinkedList(arr1);
    vector<int> arr2={5,6,4};
    Node* head2=arrayToLinkedList(arr2);
    add(head1,head2);
    return 0;
}
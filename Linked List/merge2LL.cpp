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


void traverse(Node* head){
    Node* temp=head;
    while(temp){
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



Node* brute(Node* head1,Node* head2){
    vector<int> arr;
    Node* temp=head1;
    while(temp!=NULL){
        arr.push_back(temp->data);
        temp=temp->next;
    }
    temp=head2;
    while(temp!=NULL){
        arr.push_back(temp->data);
        temp=temp->next;
    }
    sort(begin(arr),end(arr));
    Node* mergedHead=arrayToLinkedList(arr);
    return mergedHead;
}




Node* optimal(Node* head1,Node* head2){
    Node* dummy=new Node(-1);
    Node* temp1=head1;
    Node* temp2=head2;
    Node* mainTemp=dummy;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data<temp2->data){
            mainTemp->next=temp1;
            mainTemp=temp1;
            temp1=temp1->next;
        }
        else{
            mainTemp->next=temp2;
            mainTemp=temp2;
            temp2=temp2->next;
        }
    }
    if(temp1!=NULL) mainTemp->next=temp1;
    if(temp2!=NULL) mainTemp->next=temp2;
    return dummy->next;
}




int main(){
    vector<int> arr1={1,3,5};
    Node* head1=arrayToLinkedList(arr1);
    vector<int> arr2={0,2,4,6,8};
    Node* head2=arrayToLinkedList(arr2);

    Node* newHead=optimal(head1,head2);
    traverse(newHead);

    return 0;
}
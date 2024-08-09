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


void brute(Node* &head){
    Node* temp=head;
    vector<int> arr;
    while(temp!=NULL){
        arr.push_back(temp->data);
        temp=temp->next;
    }
    sort(begin(arr),end(arr));
    temp=head;
    int index=0;
    while(temp!=NULL){
        temp->data=arr[index];
        index++;
        temp=temp->next;
    }
}




Node* mergeLL(Node* head1,Node* head2){
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



Node* findMiddle(Node* head){
    Node* slow=head;
    Node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}



Node* optimalMergeSort(Node* &head){
    if(head==NULL || head->next==NULL) return head;
    Node* middleNode=findMiddle(head);
    Node* leftHead=head;
    Node* rightHead=middleNode->next;
    middleNode->next=NULL;
    leftHead=optimalMergeSort(leftHead);
    rightHead=optimalMergeSort(rightHead);
    return mergeLL(leftHead,rightHead);
    
}



void print(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}



int main(){
    vector<int> arr={1,2,3,5,4,7,6,9,8,1,2};
    Node* head=arrayToLinkedList(arr);
    // brute(head);
    // print(head);
    optimalMergeSort(head);
    print(head);
    return 0;
}
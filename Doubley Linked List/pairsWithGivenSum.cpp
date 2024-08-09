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


void brute(Node*&head,int target){
    vector<pair<int,int>> arr;
    Node* temp1=head;
    while(temp1!=NULL){
        Node* temp2=temp1->next;
        while(temp2!=NULL){
            if(temp1->data+temp2->data==target) arr.push_back({temp1->data,temp2->data});
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
    cout<<"Pairs with target are: "<<endl;
    for(int i=0;i<arr.size();i++){
        cout<<arr[i].first<<" "<<arr[i].second<<endl;
    }
}



void optimal(Node*&head,int target){
    vector<pair<int,int>> arr;
    Node* start=head;
    Node* end=head;
    while(end->next!=NULL) end=end->next;
    while(start->data<=end->data){
        if(start->data+end->data==target){
            arr.push_back({start->data,end->data});
            start=start->next;
            end=end->prev;
        }
        else if(start->data+end->data<target) start=start->next;
        else end=end->prev;
    }
    cout<<"Pairs with target are: "<<endl;
    for(int i=0;i<arr.size();i++){
        cout<<arr[i].first<<" "<<arr[i].second<<endl;
    }
}



int main(){
    vector<int> arr={0,1,2,3,4,5,6,7,8,9};
    Node* head=arrayToLinkedList(arr);
    brute(head,7);
    optimal(head,7);
    return 0;
}
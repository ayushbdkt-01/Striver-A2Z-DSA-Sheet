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



void deleteKthElement1(Node* &head,int k){
    if(head==NULL) return;
    Node* temp=head;
    if(k==1){
        head=head->next;
        delete temp;
        return;
    }
    int count=1;
    Node* prev=NULL;
    while(temp!=NULL && count<k){
        count++;
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    delete temp;
}





void deleteKthElement2(Node* &head,int k){
    if(head==NULL) return;
    Node* temp=head;
    if(k==1){
        head=head->next;
        delete temp;
        return;
    }
    int count=0;
    Node* prev=NULL;
    while(temp){
        count++;
        if(count==k){
            prev->next=temp->next;
            delete temp;
            return;
        }
        prev=temp;
        temp=temp->next;
    }
    cout<<"Invalid Position"<<endl;
}




int main(){
    vector<int> arr={10,23,21,22,34,56,76};
    Node* head=arrayToLinkedList(arr);
    cout<<"Before Deletion: ";
    traversal(head);
    deleteKthElement2(head,3);
    cout<<"After Deletion: ";
    traversal(head);

    return 0;
}
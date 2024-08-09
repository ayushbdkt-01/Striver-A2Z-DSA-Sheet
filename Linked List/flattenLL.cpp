#include <bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    Node* next;
    Node* child;
    Node(int x){
        data=x;
        next=NULL;
        child=NULL;
    }
};



Node* arrayToLinkedList(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* temp=head;
    for(int i=1;i<arr.size();i++){
        Node* newNode=new Node(arr[i]);
        temp->next=newNode;
        temp=newNode;
    }
    return head;
}



Node* createUnflattenedList() {
    Node* head = new Node(1);
    Node* node2 = new Node(22);
    Node* node3 = new Node(3);
    Node* node4 = new Node(41);
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    Node* node5 = new Node(5);
    Node* node6 = new Node(61);
    node2->child = node5;
    node5->next = node6;
    Node* node7 = new Node(73);
    node5->child = node7;
    return head;
}




void traverse(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->child;
    }cout<<endl;
}




void brute(Node* &head){
    vector<int> arr;
    Node* temp=head;
    while(temp!=NULL){
        Node* childTemp=temp;
        while(childTemp!=NULL){
            arr.push_back(childTemp->data);
            childTemp=childTemp->child;
        }
        temp=temp->next;
    }
    sort(arr.begin(),arr.end());
    head=arrayToLinkedList(arr);
}




Node* mergeLL(Node* &head1,Node* &head2){
    Node* dummy=new Node(-1);
    Node* temp1=head1;
    Node* temp2=head2;
    Node* mainTemp=dummy;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data<temp2->data){
            mainTemp->child=temp1;
            mainTemp=temp1;
            temp1=temp1->child;
        }
        else{
            mainTemp->child=temp2;
            mainTemp=temp2;
            temp2=temp2->child;
        }
        mainTemp->next=NULL;
    }
    if(temp1!=NULL) mainTemp->child=temp1;
    if(temp2!=NULL) mainTemp->child=temp2;
    dummy->child->next=NULL;
    return dummy->child;
}



Node* optimal(Node* &head){
    if(head==NULL || head->next==NULL) return head;
    Node* mergedHead=optimal(head->next);
    return mergeLL(head,mergedHead);
}


int main() {
    Node* head = createUnflattenedList();
    // brute(head);
    // traverse(head);
    head=optimal(head);
    traverse(head);


    return 0;
}

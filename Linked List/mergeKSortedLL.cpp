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



Node* brute(vector<Node*> &lists){
    vector<int> arr;
    for(int i=0;i<lists.size();i++){
        Node* head=lists[i];
        while(head!=NULL){
            arr.push_back(head->data);
            head=head->next;
        }
    }
    sort(arr.begin(),arr.end());
    Node* ansHead=arrayToLinkedList(arr); 
    return ansHead;  
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



Node* optimal(vector<Node*> &lists){
    Node* head=lists[0];
    for(int i=1;i<lists.size();i++){
        head=mergeLL(head,lists[i]);
    }
    return head;
}



Node* moreOptimal(vector<Node*> &lists){
    priority_queue<  pair<int,Node*>,   vector<pair<int,Node*>>,  greater<pair<int,Node*>>   > pq;

    for(int i=0;i<lists.size();i++){
        if(lists[i]!=NULL) pq.push({lists[i]->data,lists[i]});
    }
    Node* dummy= new Node(-1);
    Node* temp=dummy;
    while(!pq.empty()){
        pair<int,Node*> p= pq.top();
        temp->next=p.second;
        pq.pop();
        if(p.second->next!=NULL) pq.push({p.second->next->data,p.second->next});
        temp->next=p.second;
        temp=temp->next;
    }
    return dummy->next;
}




int main(){
    vector<int> arr1={1,3,5};
    Node* head1=arrayToLinkedList(arr1);
    vector<int> arr2={0,2,4};
    Node* head2=arrayToLinkedList(arr2);
    vector<int> arr3={6,8,10};
    Node* head3=arrayToLinkedList(arr3);
    vector<int> arr4={7,9,11};
    Node* head4=arrayToLinkedList(arr4);

    vector<Node*> lists={head1,head2,head3,head4};

    // Node* newHead=brute(lists);
    // traverse(newHead);

    // Node* newHead=optimal(lists);
    // traverse(newHead);

    Node* newHead=moreOptimal(lists);
    traverse(newHead);


    

    
    return 0;
}
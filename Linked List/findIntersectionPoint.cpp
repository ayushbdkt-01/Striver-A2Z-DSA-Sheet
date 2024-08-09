#include<bits/stdc++.h>
using namespace std;

struct Node{
int data;
Node* next;
Node(int d){
    data=d;
    next=NULL;
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



void traverse(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}


Node* brute(Node* &head1,Node* &head2){
    unordered_map<Node*,int> m;
    Node* temp=head1;
    while(temp!=NULL){
        m[temp]=temp->data;
        temp=temp->next;
    }

    temp=head2;
    while(temp!=NULL){
        if(m.find(temp)!=m.end()) return temp;
        temp=temp->next;
    }
    return NULL;
}

Node* optimal(Node* &head1,Node* &head2){
    Node* temp1=head1;
    Node* temp2=head2;
    while(temp1!=temp2){
        temp1=temp1->next;
        temp2=temp2->next;
        if(temp2==temp1) return temp1;
        if(temp1==NULL) temp1=head2;
        if(temp2==NULL) temp2=head1;
    }
    return temp1;
}


Node* intersectionPoint(Node* &largeHead,Node* &smallHead,int steps){
    Node* largeTemp=largeHead;
    Node* smallTemp=smallHead;
    while(steps--) largeTemp=largeTemp->next;
    while(largeTemp!=smallTemp){
        largeTemp=largeTemp->next;
        smallTemp=smallTemp->next;
    }
    if(largeTemp==smallTemp) return largeTemp;
    else return NULL;
}




Node* better(Node* &head1,Node* &head2){
    int n1=0,n2=0;
    Node* temp1=head1;
    Node* temp2=head2;
    while(temp1!=NULL){
        n1++;
        temp1=temp1->next;
    }
    while(temp2!=NULL){
        n2++;
        temp2=temp2->next;
    }

    if(n1>n2){
        return intersectionPoint(head1,head2,n1-n2); // small LL, larger LL, steps.
    }
    else{
        return intersectionPoint(head2,head1,n2-n1);
    }
}

int main(){
    vector<int> arr={10,23,21};
    Node* head1=arrayToLinkedList(arr);
    Node* head2=arrayToLinkedList(arr);

    cout<<"Intersection point: "<<brute(head1,head2)->data<<endl;;

    return 0;
}
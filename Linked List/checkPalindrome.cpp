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



void print(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}


void brute1(Node* &head){
    // use array to check palindrome data of LL.
    Node* temp=head;
    vector<int> arr;
    while(temp!=NULL){
        arr.push_back(temp->data);
        temp=temp->next;
    }
    int s=0,e=arr.size()-1;
    while(s<e){
        if(arr[s]!=arr[e]){
            cout<<"Linked List is not Palindrome"<<endl;
            return;
        }
        s++,e--;
    }
    cout<<"Linked List is Palindrome"<<endl;
}



void brute2(Node* &head){
    // use stack to check palindrome data of LL.
    Node* temp=head;
    stack<int>s;
    while(temp!=NULL){
        s.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        if(temp->data!=s.top()){
            cout<<"Linked List is not Palindrome"<<endl;
            return;
        }
        s.pop();
       temp=temp->next;
    }
    cout<<"Linked List is Palindrome"<<endl;
}



void reverse(Node* &head){
    Node* prev=NULL;
    Node* temp=head;
    while(temp!=NULL){
        Node* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    head=prev;
}



void optimal(Node* &head){
    // find middle of LL using slow/fast pointers.
    // Divide the LL into 2 halves wrt middle.
    // Reverse the 2nd half.
    // If both halves are equal, LL is palindrome.
    // Else LL is not palindrome.
    Node* fast=head;
    Node* slow=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    Node* head1=head;
    Node* head2=slow->next;
    slow->next=NULL;
    reverse(head2);
    Node* temp1=head1;
    Node* temp2=head2;
    while(temp2!=NULL){
        if(temp1->data != temp2->data){
            cout<<"Not palindrome"<<endl;
            return;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    cout<<"Linked list is Palindrome"<<endl;
}



int main(){
    vector<int> arr={1,2,3,3,2,1};
    Node* head=arrayToLinkedList(arr);
    brute1(head);
    brute2(head);
    optimal(head);
    return 0;
}
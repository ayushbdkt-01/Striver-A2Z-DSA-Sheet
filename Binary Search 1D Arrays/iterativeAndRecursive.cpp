#include<bits/stdc++.h>
using namespace std;



void iterative(int a[],int n,int s,int e,int key){
    int mid=(s+e)/2;
    while(s<=e){
        if(a[mid]==key){
            cout<<"Found at index: "<<mid<<endl;
            return;
        }
        else if(a[mid]>key) e=mid-1;
        else s=mid+1;
        mid=(s+e)/2;
    }
    cout<<"Not Found"<<endl;
}



void recursive(int a[],int n,int s,int e,int key){
    if(s>e){
        cout<<"Not Found"<<endl;
        return;
    }
    int mid=(s+e)/2;
    if(a[mid]==key){
        cout<<"Found at index: "<<mid<<endl;
        return;
    }
    else if(key>a[mid]) return recursive(a,n,mid+1,e,key);
    else return recursive(a,n,s,mid-1,key);
}



int main(){
    int a[]={2,4,6,8,10,12,14};
    int n=7;
    int key=12;

    iterative(a,n,0,n-1,key);
    recursive(a,n,0,n-1,key);
    return 0;
}
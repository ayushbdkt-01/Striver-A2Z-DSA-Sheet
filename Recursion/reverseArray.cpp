#include<bits/stdc++.h>
using namespace std;

void reverse(int* arr,int s,int e){
    if(s>=e) return;
    swap(arr[s],arr[e]);
    reverse(arr,s+1,e-1);
}

void reverse2(int* arr,int n,int s){
    if(s>n/2) return;
    swap(arr[s],arr[n-s-1]);
    reverse(arr,n,s+1);
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    int n=9;
    reverse2(arr,9,0);
    cout<<"Reversed array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}
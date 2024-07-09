#include<bits/stdc++.h>
using namespace std;


void brute(int a[],int n){
    // insert all non-zero elements in the new array. Insert the non-zero elements in the starting of the array and insert 0 at the remaining indexes.
    vector<int> temp;
    for(int i=0;i<n;i++){
        if(a[i]!=0){
            temp.push_back(a[i]);
        }
    }
    for(int i=0;i<temp.size();i++){
        a[i]=temp[i];
    }
    for(int i=temp.size();i<n;i++){
        a[i]=0;
    }
}



void optimized(int a[],int n){
    // j stores the index of the first zero-index. traverse the array and if any non-zero element is found, swap it with the a[j] as a[j]==0 and increment j.
    int j=0;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            j=i;
            break;
        }
    }
    for(int i=j+1;i<n;i++){
        if(a[i]!=0){
            swap(a[i],a[j]);
            j++;
        }
    }
}



int main(){
    int a[]={0,1,2,0,3,0,0,4,3,2,0};
    int n=11;

    optimized(a,n);
    cout<<"Modified array: ";
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}
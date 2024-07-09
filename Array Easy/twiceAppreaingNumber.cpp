#include<bits/stdc++.h>
using namespace std;


void brute(int a[],int n){
    // count the freq of each element in the array using linear search and if freq==1, this is the required element.
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(a[i]==a[j]){
                count++;
            }
        }
        if(count==1){
            cout<<"The element is: "<<a[i]<<endl;
            return;
        }
    }
}


void better1(int a[],int n){
    // using hash array to store the frequency and then checking the freq==1, this is our element.
    int hash[n+1]={0};
    for(int i=0;i<n;i++){
        hash[a[i]]++;
    }
    for(int i=0;i<=n;i++){
        if(hash[i]==1){
            cout<<"The element is: "<<i<<endl;
            return;
        }
    }
}



void better2(int a[],int n){
    // using unordered_map to store the frequency and then checking the freq==1, this is our element.
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        m[a[i]]++;
    }
    for(auto it: m){
        if(it.second == 1){
            cout<<"The number is: "<<it.first<<endl;
            return;
        }
    }
}



void optimized(int a[],int n){
    // X-OR of all elements will eliminate all the elements appearing twice and remains with the only element occurring once.
    int xorr=0;
    for(int i=0;i<n;i++){
        xorr=xorr^a[i];
    }
    cout<<"The number is: "<<xorr<<endl;
}



int main(){
    // given an array in which all elements appears twice except one which appears once. Find the element which appears once.

    int a[]={1,2,1,3,3,4,5,5,4};
    int n=9;

    brute(a,n);
    better1(a,n);
    better2(a,n);
    optimized(a,n);

    return 0;
}
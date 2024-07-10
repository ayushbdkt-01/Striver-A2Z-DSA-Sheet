#include<bits/stdc++.h>
using namespace std;


void brute(int a[],int n){
    // Create two different vectors to store positive and negative elements And then traverses both arrays to insert +ve and -ve elements.
    int pos[n/2];
    int neg[n/2];

    int posIndex=0;
    int negIndex=0;
    for(int i=0;i<n;i++){
        if(a[i]>=0){
            pos[posIndex++]=a[i];
        }
        else{
            neg[negIndex++]=a[i];
        }
    }

    posIndex=0;
    negIndex=0;
    int i=0;
    while(posIndex<n/2){
        a[i]=pos[posIndex++];
        i++;
        a[i]=neg[negIndex++];
        i++;
    }

    cout<<"Modified Array: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }cout<<endl;
}



void optimized(int a[],int n){
    // Create a answer vector of N size and insert positive elements at the even index and the negative elements at the odd indexand increment the positive and negative counter by 2.
    vector<int> ans(n,0);
    int posIndex=0;
    int negIndex=1;
    for(int i=0;i<n;i++){
        if(a[i]>=0){
            ans[posIndex]=a[i];
            posIndex+=2;
        }
        else{
            ans[negIndex]=a[i];
            negIndex+=2;
        }
    }

    cout<<"Modified Array: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }cout<<endl;
}



int main(){
    // Given an array of even size and has equal number of +ve and -ve integers. change the array such that even indexes has +ve elements and odd indexes have -ve elements;
    int a[]={1,2,3,4,-1,-2,-3,-4};
    int n=8;

    brute(a,n);
    optimized(a,n);
    return 0;
}
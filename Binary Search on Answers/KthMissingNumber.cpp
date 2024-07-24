#include<bits/stdc++.h>
using namespace std;

void brute(int a[],int n,int k){
    int maxx=a[n-1];
    int count=0;
    for(int i=1;i<maxx;i++){
        bool isPresent=false;
        for(int j=0;j<n;j++){
            if(i==a[j]) isPresent=true;
        }
        if(isPresent==false) count++;
        if(count==k) cout<<"Missing number is: "<<i<<endl;
    }
}



void better(int a[],int n,int k){
    for(int i=0;i<n;i++){
        if(a[i]<k) k++;
        else break;
    }
    cout<<"Missing number is: "<<k<<endl;
}



void optimal(int a[],int n,int k){
    int s=0,e=n-1;
    while(s<=e){
        int mid=(s+e)/2;
        int missing=a[mid]-(mid+1);
        if(missing<k) s=mid+1;
        else e=mid-1;
    }
    cout<<"Missing number is: "<<s+k<<endl;
}


int main(){
    // given a sorted array, find the kth missing number from 1 to range.
    int a[]={2,3,4,7,11};
    int n=5;
    int k=5;

    brute(a,n,k);
    better(a,n,k);
    optimal(a,n,k);
    return 0;
}
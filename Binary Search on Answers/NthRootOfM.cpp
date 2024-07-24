#include<bits/stdc++.h>
using namespace std;



void brute(int n,int m){
    for(int i=1;i<=m;i++){
        int prod=1;
        for(int j=1;j<=n;j++){
            prod=prod*i;
            if(prod>m) break;
        }
        if(prod==m){
            cout<<"Nth Root is: "<<i<<endl;
            return;
        }
    }
    cout<<"Nth root doesn't exist"<<endl;
}



int findProduct(int mid,int n){
    int prod=1;
    for(int i=0;i<n;i++){
        prod*=mid;
    }
    return prod;
}



void optimal(int n,int m){
    int s=1,e=m;
    while(s<=e){
        int mid=(s+e)/2;
        if(findProduct(mid,n)==m){
            cout<<"Nth Root is: "<<mid<<endl;
            return;
        }
        else if(findProduct(mid,n)>m) e=mid-1;
        else s=mid+1;
    }
    cout<<"Nth root doesn't exist"<<endl;
}




int findProduct2(int mid,int n,int m){
    // return 1 if, prod==m
    // return 2 if, prod>m
    // return 0 if. prod<m
    int prod=1;
    for(int i=0;i<n;i++){
        prod*=mid;
        if(prod>m) return 2;
    }
    if(prod==m) return 1;
    return 0;
}



void optimal2(int n,int m){
    int s=1,e=m;
    while(s<=e){
        int mid=(s+e)/2;
        if(findProduct2(mid,n,m)==1){
            cout<<"Nth Root is: "<<mid<<endl;
            return;
        }
        else if(findProduct2(mid,n,m)==0) s=mid+1;
        else e=mid-1;
    }
    cout<<"Nth root doesn't exist"<<endl;
}




int main(){
    // Nth root of M means ---> N^?=M
    // n ki power kya kare ki woh M ban jaaye.
    int n=3;
    int m=64;

    brute(n,m);  // linear search
    optimal(n,m);  // binary search
    return 0;
}
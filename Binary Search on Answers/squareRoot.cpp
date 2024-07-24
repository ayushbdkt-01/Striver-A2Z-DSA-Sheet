#include<bits/stdc++.h>
using namespace std;



void brute(int n){
    int ans=1;
    for(int i=0;i<n;i++){
        if(i*i<=n) ans=i;
        else break;
    }
    cout<<"Root is: "<<ans<<endl;
}



void better(int n){
    cout<<"Root is: "<<(int)sqrt(n)<<endl;
}



void optimal(int n){
    int s=1,e=n;
    int ans=1;
    while(s<=e){
        int mid=(s+e)/2;
        if(mid*mid<=n){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    cout<<"Root is: "<<ans<<endl;
}



int main(){
    int n=28;

    brute(n);  // Linear search
    better(n); // STL
    optimal(n); // Binary Search

    return 0;
}
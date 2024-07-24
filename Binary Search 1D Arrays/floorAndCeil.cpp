#include<bits/stdc++.h>
using namespace std;



void floor(int a[],int n,int x){
    int s=0,e=n-1;
    int mid=(s+e)/2;
    int ans=-1;
    while(s<=e){
        if(a[mid]<=x){
            ans=a[mid];
            s=mid+1;
        }
        else e=mid-1;
        mid=(s+e)/2;
    }
    cout<<"Floor element is: "<<ans<<endl;
}



void ceil(int a[],int n,int x){
    int s=0,e=n-1;
    int mid=(s+e)/2;
    int ans=-1;
    while(s<=e){
        if(a[mid]>=x){
            ans=a[mid];
            e=mid-1;
        }
        else  s=mid+1;
        mid=(s+e)/2;
    }
    cout<<"Ceil element is: "<<ans<<endl;
}



int main(){
    int a[]={10,20,30,40,50};
    int n=5;
    int x=25;

    // FLoor is the largest number in the array which is <= x .... Basically the lower bound.
    
    // Ceil is the smallest number in the array which is >= x .... Basically the upper bound.

    floor(a,n,x);
    ceil(a,n,x);
    return 0;
}
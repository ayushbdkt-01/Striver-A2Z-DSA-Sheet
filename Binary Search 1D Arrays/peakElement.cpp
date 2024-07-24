#include<bits/stdc++.h>
using namespace std;



int brute(int a[],int n){
    // traversing the loop and checking that curr>prev and curr>next and handling edge cases separately with first and the last element.
    for(int i=0;i<n;i++){
        if(i==0){
            if(a[i]>a[i+1]) return a[i]; 
        }
        else if(i==n-1){
            if(a[i]>a[i-1]) return a[i];
        }
        else{
            if(a[i]>a[i+1] && a[i]>a[i-1]) return a[i];
        }
    }
    return -1;
}



int optimal(int a[],int n){
    // Applying binary search on array and checking that curr>prev and curr>next and handling edge cases separately with first and the last element.
    if(n==1) return a[0];
    if(a[0]>a[1]) return a[0];
    if(a[n-1]>a[n-2]) return a[n-1];

    int s=1,e=n-2;
    while(s<=e){
        int mid=(s+e)/2;
        if(a[mid]>a[mid-1] && a[mid]>a[mid+1]) return a[mid];
        else if(a[mid]>a[mid-1]) s=mid+1;
        else e=mid-1;
    }
    return -1;
}



int main(){
    int a[]={1,2,3,4,5,6,7,8,5,1};
    int n=10;

    cout<<"Peak Element is: "<<optimal(a,n)<<endl;
    cout<<"Peak Element is: "<<brute(a,n)<<endl;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;


void brute(int a[],int n,int target){
    // for each element, check each element that the sum is equal to target or not.
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]+a[j]==target){
                cout<<"Target found at index: "<<i<<" and "<<j<<endl;
            }
        }
    }
    cout<<endl;
}



void better(int arr[],int n,int target){
    // using a map to store the target-a[i] and search for this in the map, if gfound, this is the required pair
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        int a=arr[i];
        int b=target-a;
        if(m.find(b)!=m.end()){
            cout<<"Target at: "<<i<<" and "<<m[b]<<endl;
        }
        m[a]=i;
    }
    cout<<endl;
}



void optimized(int a[],int n,int target){
    // sort the array and find pairs equal to target sum using two-pointer approach.
    sort(a,a+n);
    int s=0,e=n-1;
    while(s<e){
        if(a[s]+a[e]==target){
            cout<<"Target found at element: "<<a[s]<<" and "<<a[e]<<endl;
            s++,e--;
        }
        else if(a[s]+a[e]<target){
            s++;
        }
        else{
            e--;
        }
    }
    cout<<endl;
}




int main(){
    int a[]={1,3,5,2,4,7,6,4};
    int n=8;
    int target=10;

    brute(a,n,target);
    better(a,n,target);
    optimized(a,n,target);
    return 0;
}
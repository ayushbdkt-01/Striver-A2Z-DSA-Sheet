#include<bits/stdc++.h>
using namespace std;



void optimal(int a[],int n,int target){
    int s=0;
    int e=n-1;
    int mid=(s+e)/2;
    int ans=n;
    while(s<=e){
        if(a[mid]>=target){
            ans=mid;
            e=mid-1;
        }
        else s=mid+1;
        mid=(s+e)/2;
    }
    cout<<"Insert Position is: "<<ans<<endl;
}



int main(){
    int a[]={1,2,3,4,5,6,7,8,9};
    int n=9;
    int target=5;

    optimal(a,n,target);  // optimal

    return 0;
}
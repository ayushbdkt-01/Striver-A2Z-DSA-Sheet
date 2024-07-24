#include<bits/stdc++.h>
using namespace std;


void optimal(int a[],int n){
    int s=0,e=n-1;
    int ans=INT_MAX;
    int index=-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(a[s]<=a[mid]){
            s=mid+1;
            if(a[s]<ans){
                ans=a[s];
                index=s;
            }
        }
        else{
            e=mid-1;
            if(ans<a[mid]){
                ans=a[mid];
                index=mid;
            }
        }
    }
    cout<<"Minimum ELement is: "<<ans<<endl;
    cout<<"Number of times the array has been rotated(index of minimum element): "<<index<<endl;
}


int main(){
    // the index of minimum element is same as the number of times the array has been rotated.
    int a[]={6,7,8,9,1,2,3,4,5};
    int n=9;

    optimal(a,n);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;



void optimal(int a[],int n){
    int s=0,e=n-1;
    int ans=INT_MAX;
    while(s<=e){
        int mid=(s+e)/2;
        if(a[s]<=a[mid]){
            ans=min(ans,a[s]);
            s=mid+1;
        }else{
            ans=min(ans,a[mid]);
            e=mid-1;
        }
    }
    cout<<"Minimum Element is: "<<ans<<endl;
}



int main(){
    int a[]={5,6,7,8,1,2,3,4};
    int n=8;

    optimal(a,n);
    return 0;
}
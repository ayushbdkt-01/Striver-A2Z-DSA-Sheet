#include<bits/stdc++.h>
using namespace std;



void linearSearch(int a[],int n,int x){
    for(int i=0;i<n;i++){
        if(a[i]>=x){
            cout<<"Lower bound is: "<<i<<endl;
            return;
        }
    }
    cout<<"Lower bound is: "<<n<<endl;
}



void binarySearch(int a[],int n,int x){
    int s=0;
    int e=n-1;
    int mid=(s+e)/2;
    int ans=n;
    while(s<=e){
        if(a[mid]>=x){
            ans=mid;
            e=mid-1;
        }
        else s=mid+1;
        mid=(s+e)/2;
    }
    cout<<"Lower bound is: "<<ans<<endl;
}



int main(){
    // lower bound smallest index such that a[index]>=x (x is input)
    int a[]={1,2,3,4,5,6,7,8,9};
    int n=9;
    int x=5;

    linearSearch(a,n,x);  // brute
    binarySearch(a,n,x);  // optimal

    // lower bound using STL.
    // lower_bound(nums.begin(),nums.end(),x)-nums.begin();
    // the function lower_bound() returns an iterator.
    int index=lower_bound(a,a+n,x)-a;
    cout<<"Lower bound is: "<<index<<endl;
    return 0;
}
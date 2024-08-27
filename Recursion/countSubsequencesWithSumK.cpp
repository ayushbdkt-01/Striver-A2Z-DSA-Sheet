#include<bits/stdc++.h>
using namespace std;


int withSumK(int arr[],int n, int sum,int index,int target){
    if(sum>target) return 0;
    if(index>=n){
        if(sum==target) return 1;
        else return 0;
    }
    sum+=arr[index];
    int left=withSumK(arr,n,sum,index+1,target);
    sum-=arr[index];
    int right=withSumK(arr,n,sum,index+1,target);
    return left+right;
}


int main(){
    int a[]={1,2,3,4};
    int n=4;
    int k=5; // target sum.
    cout<<"Count of subseqences with sum as K: "<<withSumK(a,n,0,0,k)<<endl;
    return 0;
}
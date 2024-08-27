#include<bits/stdc++.h>
using namespace std;


void withSumK(int arr[],vector<int> &ans,int n, int sum,int index,int target){
    if(index>=n){
        if(sum==target){
            for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
            cout<<endl;
        }
        return;
    }
    ans.push_back(arr[index]);
    sum+=arr[index];
    withSumK(arr,ans,n,sum,index+1,target);
    sum-=arr[index];
    ans.pop_back();
    withSumK(arr,ans,n,sum,index+1,target); 
}


int main(){
    int a[]={1,2,3,4};
    int n=4;
    int k=5; // target sum.
    vector<int> ans;
    withSumK(a,ans,n,0,0,k);
    return 0;
}
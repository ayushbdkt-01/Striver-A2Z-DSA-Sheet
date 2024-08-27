#include<bits/stdc++.h>
using namespace std;


bool withSumK(int arr[],vector<int> &ans,int n, int sum,int index,int target){
    if(index>=n){
        if(sum==target){
            for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
            cout<<endl;
            return true;
        }
        return false;
    }
    ans.push_back(arr[index]);
    sum+=arr[index];
    if(withSumK(arr,ans,n,sum,index+1,target)==true) return true;
    sum-=arr[index];
    ans.pop_back();
    if(withSumK(arr,ans,n,sum,index+1,target)) return true;
    return false; 
}


int main(){
    int a[]={1,2,3,4};
    int n=4;
    int k=5; // target sum.
    vector<int> ans;
    withSumK(a,ans,n,0,0,k);
    return 0;
}
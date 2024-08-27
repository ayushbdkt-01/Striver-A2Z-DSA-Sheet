#include<bits/stdc++.h>
using namespace std;


void subsequence(int arr[],int n,int index,vector<int> &ans){
    if(index>=n){
        for(auto it: ans) cout<<it<<" ";
        if(ans.size()==0) cout<<"{}"<<" ";
        cout<<endl;
        return;
    }
    // pick element
    ans.push_back(arr[index]);
    subsequence(arr,n,index+1,ans);

    // don't pick the element.
    ans.pop_back();
    subsequence(arr,n,index+1,ans);
}


// TC = 2^n * n
// SC = n (stack space)
int main(){
    int arr[]={3,1,2};
    int n=3;
    vector<int> ans;
    subsequence(arr,n,0,ans);
    return 0;
}
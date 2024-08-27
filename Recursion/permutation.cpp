#include<bits/stdc++.h>
using namespace std;


void func(int arr[],int n,int index,vector<int> &ans,vector<vector<int>> &finalAns,vector<int>&mapp){
    if(ans.size()==n){
        for(auto it: ans) cout<<it<<" ";
        cout<<endl;
        finalAns.push_back(ans);
        return;
    }
    for(int i=0;i<n;i++){
        if(mapp[i]==0){
            ans.push_back(arr[i]);
            mapp[i]=1;
            func(arr,n,index,ans,finalAns,mapp);
            mapp[i]=0;
            ans.pop_back();
        }
    }
}


int main(){
    int arr[]={1,2,3};
    int n=3;
    vector<int> ans;
    vector<int>mapp(n,0);
    vector<vector<int>> finalAns;
    func(arr,n,0,ans,finalAns,mapp);
    return 0;
}
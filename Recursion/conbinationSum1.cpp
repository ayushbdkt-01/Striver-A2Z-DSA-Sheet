#include<bits/stdc++.h>
using namespace std;



void func(vector<int> &arr,vector<int> &ans,vector<vector<int>> &finalAns,int index,int target){
    if(index>=arr.size()){
        if(target==0) finalAns.push_back(ans);
        return;
    }
    if(arr[index]<=target){
        ans.push_back(arr[index]);
        func(arr,ans,finalAns,index,target-arr[index]);
        ans.pop_back();
    }
    func(arr,ans,finalAns,index+1,target);
}



int main(){
    vector<int> arr={2,3,6,7};
    vector<int> ans;
    vector<vector<int>> finalAns;
    int target=7;
    func(arr,ans,finalAns,0,target);

    for(int i=0;i<finalAns.size();i++){
        vector<int> temp=finalAns[i];
        for(int j=0;j<temp.size();j++){
            cout<<temp[j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
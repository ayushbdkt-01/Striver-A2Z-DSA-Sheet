#include<bits/stdc++.h>
using namespace std;



void func(vector<int> &arr,vector<int> &ans,vector<vector<int>> &finalAns,int index,int target){
    if(target==0) {
        finalAns.push_back(ans);
        return;
    }
    for(int i=index;i<arr.size();i++){
       if(i>index && arr[i]==arr[i-1]) continue;
        if(arr[i]>target) break;
            ans.push_back(arr[i]);
            func(arr,ans,finalAns,i+1,target-arr[i]);
            ans.pop_back();
    }
}



int main(){
    vector<int> arr={10,1,2,7,6,1,5};
    sort(arr.begin(),arr.end());
    vector<int> ans;
    vector<vector<int>> finalAns;
    int target=8;
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
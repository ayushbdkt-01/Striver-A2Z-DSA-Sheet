#include<bits/stdc++.h>
using namespace std;



void func(int arr[], vector<int>&ans,int n,int sum,int index){
    if(index>=n){
        ans.push_back(sum);
        return;
    }
    func(arr,ans,n,sum+arr[index],index+1); // pick element
    func(arr,ans,n,sum,index+1); // do not pick element.
}



int main(){
    int arr[]={1,2,3,4,5};
    int n=5;
    vector<int> ans;
    func(arr,ans,n,0,0);
    sort(ans.begin(),ans.end());
    for(auto it: ans) cout<<it<<" ";
    cout<<endl;
    return 0;
}
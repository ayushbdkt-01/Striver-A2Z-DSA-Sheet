#include<bits/stdc++.h>
using namespace std;


void brute(int a[],int n){ 
    // For each element in the array, cheque all the right elements, if any element is larger than the current elements, then this is not the leader element. If all the iterations to the right, all the elements are smaller than the current element, then the current element is the leader element
    vector<int> ans;
    for(int i=0;i<n;i++){
        bool leader=true;
        for(int j=i+1;j<n;j++){
            if(a[i]<a[j]){
                leader=false;
                break;
            }
        }
        if(leader==true){
            ans.push_back(a[i]);
        }
    }

    cout<<"Leader elements are: ";
    for(auto it: ans){
        cout<<it<<" ";
    }
}


void optimized(int a[],int n){
    // Treverse from the end of the array and Maintain a maximum element if the current element is greater than the maximum element, update the maximum elementand make the current element as the leader element
    int maxElement=INT_MIN;
    vector<int> ans;
    for(int i=n-1;i>=0;i--){
        if(a[i]>maxElement){
            ans.push_back(a[i]);
        }
        maxElement=max(a[i],maxElement);
    }
    cout<<"Leader elements are: ";
    for(auto it: ans){
        cout<<it<<" ";
    }
}


int main(){
    int a[]={10,12,22,3,0,6};
    int n=6;

    brute(a,n);
    optimized(a,n);
    return 0;
}

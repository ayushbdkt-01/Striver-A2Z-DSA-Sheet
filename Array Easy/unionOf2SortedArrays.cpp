#include<bits/stdc++.h>
using namespace std;



void brute(int a[],int n1,int b[],int n2){
    // use a set and traverse both the arrays one by one and insert all elements into the set. Set stores only unique elements and also in sorted order.
    set<int> s;
    for(int i=0;i<n1;i++){
        s.insert(a[i]);
    }
    for(int i=0;i<n2;i++){
        s.insert(b[i]);
    }
    cout<<"Union: ";
    for(auto it:s){
        cout<<it<<" ";
    }
}



void optimized(int a[],int n1,int b[],int n2){
    // two-pointer approach = i at a[0] and j at b[0]. check which is smaller and also check that the last element of the answer array shouldn't be equal to the current element because we need unique elements.
    int i=0;
    int j=0;
    vector<int> ans;
    while(i<n1 && j<n2){
        if(a[i]<=b[j]){
            if(ans.size()==0 || ans.back()!=a[i]){
                ans.push_back(a[i]);
            }
            i++;
        }
        else{
            if(ans.size()==0 || ans.back()!=b[j]){
                ans.push_back(b[j]);
            }
            j++;
        }
    }
    while(i<n1){
        if(ans.size()==0 || ans.back()!=a[i]){
            ans.push_back(a[i]);
        }
        i++;
    }
    while(j<n2){
        if(ans.size()==0 || ans.back()!=b[j]){
            ans.push_back(b[j]);
        }
        j++;
    }

    cout<<"Union is: ";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
}



int main(){
    int a[]={1,2,3,4,5,6};
    int b[]={4,5,6,7,8,9};
    int n1=6;
    int n2=6;

    optimized(a,n1,b,n2);
    
    return 0;
}
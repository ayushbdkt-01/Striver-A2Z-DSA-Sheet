#include<bits/stdc++.h>
using namespace std;



void brute(int a[],int n,int target){
    // use 3 nested loops to find the target.
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(a[i]+a[j]+a[k]==target){
                    cout<<"Target is: "<<a[i]<<" "<<a[j]<<" "<<a[k]<<endl;
                }
            }
        }
    }
}



void better(int a[],int n,int target){
    // using a set to store the third number and checking for the third number in the set.
    set<vector<int>> s;
    for(int i=0;i<n;i++){
        set<int> hashset;
        for(int j=i+1;j<n;j++){
            int third=target-(a[i]+a[j]);
            if(hashset.find(third) != hashset.end()){
                vector<int> temp={a[i],a[j],third};
                sort(temp.begin(),temp.end());
                s.insert(temp);
            }
            hashset.insert(a[j]);
        }
    }
    vector<vector<int>> ans(s.begin(),s.end());
    cout<<"Targets are: "<<endl;
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}


void optimized(int a[],int n,int target){
    // sorting the array and using two-pointer to find the target indexes.
    sort(a,a+n);
    for(int i=0;i<n;i++){
        int j=i+1;
        int k=n-1;
        while(j<k){ 
            int sum=a[i]+a[j]+a[k];
            if(sum==target){
                cout<<"Target is: "<<a[i]<<" "<<a[j]<<" "<<a[k]<<endl;
                j++,k--;
            }
            else if(sum<target){
                j++;
            }
            else{
                k--;
            }
        }
    }
}


int main(){
    int a[]={1,2,3,4,5,6,7,8};
    int n=8;
    int target=10;

    brute(a,n,target);
    better(a,n,target);
    optimized(a,n,target);
    return 0;
}
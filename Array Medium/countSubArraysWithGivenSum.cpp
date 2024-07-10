#include<bits/stdc++.h>
using namespace std;


void brute(int a[],int n,int target){
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum+=a[k];
            }
            if(sum==target){
                count++;
            }
        }
    }
    cout<<"SubArrays with given sum are: "<<count<<endl;
}



void better(int a[],int n,int target){
    int count=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=a[j];
            if(sum==target){
                count++;
            }
        }
    }
    cout<<"SubArrays with given sum are: "<<count<<endl;
}




void optimized(int a[],int n,int target){
    // uses prefix sum ...smajh nhiii aya 
    // Bad m krunga
}



int main(){
    int a[]={1,2,3,-3,1,1,1,4,2,-3};
    int n=10;
    int target=3;

    brute(a,n,target);
    better(a,n,target);
    return 0;
}
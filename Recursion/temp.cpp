#include<bits/stdc++.h>
using namespace std;


int func(int arr[],int index,int n,int sum){
    if(index>=n){
        if(sum==0) return 1;
        else return 0;
    }
    int left=func(arr,index+1,n,sum-arr[index]);
    int right=func(arr,index+1,n,sum);
    return left+right;
}


int main(){
    int arr[]={1,2,1};
    int n=3;
    int index=0;
    int sum=3;
    cout<<"Count is: "<<func(arr,index,n,sum);
    return 0;
}
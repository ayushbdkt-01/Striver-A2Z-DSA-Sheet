#include<bits/stdc++.h>
using namespace std;


void brute(int a[],int n,int target){
    // generate all sub-arrays and store the length of the maximum sub-array.
    int len=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum = sum + a[k];
            }
            if(sum==target){
                len=max(len,j-i+1);
            }
        }
    }
    cout<<"Maximum Length: "<<len<<endl;
}



void better(int a[],int n,int target){
    int len=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum = sum + a[j];
            if(sum==target){
                len=max(len,j-i+1);
            }
        }
    }
    cout<<"Maximum Length: "<<len<<endl;
}




void optimized(int a[],int n,int target){
    cout<<"Smajh nhii aya ...bad m krunga. ";
    cout<<"Uses concept of prefix Sum"<<endl;
}



int main(){
    // given an array and a target sum, find the length of the longest subArray with the target sum.

    int a[]={1,2,3,4,5,5,6,7,8,9,10};
    int n=11;
    int target=5;

    brute(a,n,target);
    better(a,n,target);
    optimized(a,n,target);
    return 0;
}
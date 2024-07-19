#include<bits/stdc++.h>
using namespace std;


void brute(int a[],int n,int target){
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int XOR=0;
            for(int k=i;k<=j;k++){
                XOR= XOR ^ a[k];
            }
            if(XOR==target) count++;
        }
    }
    cout<<"SubArrays with XOR equal to target are: "<<count<<endl;
}



void better(int a[],int n,int target){
    int count=0;
    for(int i=0;i<n;i++){
        int XOR=0;
        for(int j=i+1;j<n;j++){
            XOR= XOR ^ a[j];
            if(XOR==target) count++;
        }
    }
    cout<<"SubArrays with XOR equal to target are: "<<count<<endl;
}




void optimized(int a[],int n,int target){
    // smajh nhii aya ..bad m krunga
}



int main(){
    int a[]={4,2,2,6,4};
    int n=5;
    int target=6;

    brute(a,n,target);
    better(a,n,target);
    optimized(a,n,target);
    return 0;
}
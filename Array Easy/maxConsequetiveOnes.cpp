#include<bits/stdc++.h>
using namespace std;


void optimized(int a[],int n){
    int maxCount=0;
    int count=0;
    for(int i=0;i<n;i++){
        if(a[i]==1){
            count++;
            maxCount=max(maxCount,count);
        }
        else{
            count = 0; 
        }
    }
    cout<<"Maximum consequetive ones: "<<maxCount<<endl;
}



int main(){
    int a[]={1,1,0,1,1,1,0,1,1,0};
    int n=10;

    optimized(a,n);
    return 0;
}
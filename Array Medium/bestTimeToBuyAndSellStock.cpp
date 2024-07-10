#include<bits/stdc++.h>
using namespace std;



void brute(int a[],int n){
    int minCost=a[0];
    int maxProfit=0;
    for(int i=0;i<n;i++){
        int currentCost=a[i]-minCost;
        maxProfit=max(maxProfit,currentCost);
        minCost=min(minCost,a[i]);
    }
    cout<<"Maximum profit is: "<<maxProfit<<endl;
}



void better(int a[],int n){
    // uses DP
}



int main(){
    int a[]={7,1,5,3,6,4};
    int n=6;

    brute(a,n);
    better(a,n);
    return 0;
}
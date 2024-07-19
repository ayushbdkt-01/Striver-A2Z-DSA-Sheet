#include<bits/stdc++.h>
using namespace std;


void brute(int a[],int n){
    int maxProd=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int prod=1;
            for(int k=i;k<=j;k++){
                prod = prod*a[k];
            }
            maxProd=max(prod,maxProd);
        }
    }
    cout<<"Maximum sub-array product is: "<<maxProd<<endl;
}



void better(int a[],int n){
    int maxProd=INT_MIN;
    for(int i=0;i<n;i++){
        int prod=1;
        for(int j=i;j<n;j++){
            prod = prod*a[j];
            maxProd=max(prod,maxProd);
        }
    }
    cout<<"Maximum sub-array product is: "<<maxProd<<endl;

}


void optimized(int a[],int n){
    int ans=INT_MIN;
    int pref=1,suff=1;
    for(int i=0;i<n;i++){
        if(pref==0) pref=1;
        if(suff==0) suff=1;
        pref = pref*a[i];
        suff = suff*a[n-i-1];
        ans=max(ans,max(pref,suff));
    }
    cout<<"Max Sub-Array Product are: "<<ans<<endl;
}



int main(){
    int a[]={2,3,-2,4};
    int n=4;

    brute(a,n);
    better(a,n);
    optimized(a,n);
    return 0;
}
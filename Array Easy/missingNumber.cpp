#include<bits/stdc++.h>
using namespace std;


void brute(int a[],int n){
    // search each number in the array and if element is found, make the flag as true. if after the whole iteration, the falg is false, means that the element is not present.
    for(int i=0;i<n;i++){
        bool present=false;
        for(int j=0;j<n;j++){
            if(a[j]==i){
                present=true;
                break;
            }
        }
        if(present==false){
            cout<<"Missing number is: "<<i<<endl;
            break;
        }
    }
}


void better(int a[],int n){
    // use an map or hashArray to store the frequency of each element, if freq[i]==0, this is the missing number.
    int hash[n+1]={0};
    for(int i=0;i<n;i++){
        hash[a[i]]++;
    }
    for(int i=0;i<=n;i++){
        if(hash[i]==0){
            cout<<"MIssing element is: "<<i<<endl;
            return;
        }
    }
}



void optimized1(int a[],int n){
    // find sum of all arr[] elements and sum of n-natural number and find sumNatural-sumArr, this is the answer, just basic maths.
    int sumNatural=(n*(n+1))/2;
    int sumArr=0;
    for(int i=0;i<n;i++){
        sumArr += a[i];
    }
    int ans=sumNatural - sumArr;
    cout<<"Missing number is: "<<ans<<endl;
}



void optimized2(int a[],int n){
    // X-OR all the elements and X-OR all numbers from 0 to n, the final value is the missing number.
    int ans=0;
    for(int i=0;i<n;i++){
        ans=ans^a[i];
    }
    for(int i=0;i<=n;i++){
        ans=ans^i;
    }
    cout<<"Missing ELement is: "<<ans<<endl;
}




int main(){
    // n is given which has an arr[] of 'n' size and contains elements from 0 to n and one number is missing. Find the missing number.

    int n=5;
    int a[n]={0,1,2,4,5};


    brute(a,n);
    better(a,n);
    optimized1(a,n);
    optimized2(a,n);
    return 0;
}
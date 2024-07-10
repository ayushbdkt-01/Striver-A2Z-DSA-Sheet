#include<bits/stdc++.h>
using namespace std;


void brute(int a[],int n){
    int longest=0;
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(a[i]==a[j]){
                count++;
            }
        }
        longest=max(longest,count);
    }
    cout<<"Longest Common Subsequence: "<<longest<<endl;
}



void better(int a[],int n){
    // sort the array and find the largest subsequence
    sort(a,a+n);
    int longest=0;
    int count=0;
    int lastSmaller=a[0];
    for(int i=0;i<n;i++){
        if(a[i]-1==lastSmaller){
            count++;
            lastSmaller=a[i];
        }
        else if(a[i]!=lastSmaller){
            count=1;
            lastSmaller=a[i];
        }
        longest=max(longest,count);
    }
    cout<<"Longest Common Subsequence: "<<longest<<endl;
}



void optimized(int a[],int n){
    // smajh nhii aaya ....
}



int main(){
    int a[]={101,4,100,5,102,3,2,1};
    int n=8;

    brute(a,n);
    better(a,n);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;



void brute(int a[],int n){
    // generate all permutations and store them in a vector<vector<int>>.
    // traverse all permutation using loop and search for the current given permutation.
    // return the next permutation.
    // if the given permutation is the last permutaion, return the first permutaion (or just return the reversed array).
}



void better(int a[],int n){
    next_permutation(a,a+n);
    cout<<"Next Permutation is: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }cout<<endl;
}



void optimized(int a[],int n){
    int index=-1;  // initializing index with -1
    // traversing the array from the end to find the first small element which is the breakpoint. 
    for(int i=n-2;i>=0;i--){
        if(a[i]<a[i+1]){
            index=i;
            break;
        }
    }
    // if there is no breakpoint, means that the arrat is sorted (last permutation), in this case, simply reverse the array and return.
    if(index==-1){
        reverse(a,a+n);
        cout<<"Next Permutation is: ";
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }cout<<endl;
        return;
    }
    // again traverse from the end to find the just smaller element than arr[index] and swap it with arr[index]. 
    for(int i=n-1;i>=index;i--){
        if(a[i]>a[index]){
            swap(a[i],a[index]);
            break;
        }
    }

    // simply reverse the array from index+1 to end.
    reverse(a+index,a+n);

    cout<<"Next Permutation is: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }cout<<endl;
}



int main(){
    int a[]={2,1,5,4,3,0,0};
    int n=7;

    brute(a,n);
    better(a,n);
    optimized(a,n);
    return 0;
}
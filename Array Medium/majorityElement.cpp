#include<bits/stdc++.h>
using namespace std;


void brute(int a[],int n){
    // find the count of every element using linear search and check if count is greater than n/2.

    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(a[i]==a[j]) count++;
        }
        if(count>n/2){
            cout<<"The majority element is: "<<a[i]<<endl;
            break;
        }
    }
}




void better(int a[],int n){
    //store the count of each element in a unordered_map and check the element whehre freq > n/2.
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        m[a[i]]++;
    }
    for(auto it: m){
        if(it.second>n/2){
            cout<<"Majority ELement is: "<<it.first<<endl;
        }
    }
}



void optimized(int a[],int n){
    // Moore's voting algorithm = make arr[0] as the majority element. increment if a[0] is found in the array, decrement the count if arr[0] is not found in the array. IF the count becomes zero, update the majority element as a[i] and increment the count;
    int majorityElement=a[0];
    int count=0;
    for(int i=0;i<n;i++){
        if(count=0){
            count++;
            majorityElement==a[i];
        }
        else if(a[i]!=majorityElement){
            count--;
        }
        else if(a[i]==majorityElement){
            count++;
        }
    }
    cout<<"Majority element is: "<<majorityElement<<endl;
}



int main(){
    int a[]={3,4,5,3,4,3,4,3,3,3};
    int n=10;

    brute(a,n);
    better(a,n);
    optimized(a,n);
    return 0;
}
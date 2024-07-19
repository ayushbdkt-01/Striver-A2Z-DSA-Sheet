#include<bits/stdc++.h>
using namespace std;



void brute(int a[],int n){
    // Count the frequency of each element in the array using the linear search and check if the count is greater than N/3 if the count is greater than N/3, this is the majority element.

    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(a[i]==a[j]){
                count++;
            }
        }
        if(count>n/3){
            cout<<"Majority Element is: "<<a[i]<<endl;
            break;
        }
    }
    cout<<endl;
}



void better(int a[],int n){
    // Using an unordered map to store the frequency of each element from the array. And again, checking if the frequency is greater than N/3 then the element is the majority element.
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        m[a[i]]++;
    }

    for(auto it: m){
        if(it.second>n/3){
            cout<<"Majority Element is: "<<it.first<<endl;
            break;
        }
    }
    cout<<endl;
}


void optimized(int a[],int n){
    int count1=0, count2=0;
    int elem1=-1,elem2=-1;
    for(int i=0;i<n;i++){
        if(count1==0 && a[i] != elem2){
            count1++;
            elem1=a[i];
        }
        if(count2==0 && a[i] != elem1){
            count2++;
            elem2=a[i];
        }
        else if(a[i]==elem1){
            count1++;
        }
        else if(a[i]==elem2){
            count2++;
        }
        else{
            count1--;
            count2--;
        }
    }

    count1==0;
    count2=0;
    for(int i=0;i<n;i++){
        if(a[i]==elem1){
            count1++;
        }
        else if(a[i]==elem2){
            count2++;
        }
    }
    if(count1>n/3) cout<<"Majority element is: "<<elem1<<endl;
    if(count2>n/3) cout<<"Majority element is: "<<elem2<<endl;

}


int main(){
    // Find the element which appears more than N/3 times.
    int a[]={2,3,3,4,3,3,1,2,4,5,3,2};
    int n=12;

    brute(a,n);
    better(a,n);
    optimized(a,n);
    return 0;
}
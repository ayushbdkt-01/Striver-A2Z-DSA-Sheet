#include<bits/stdc++.h>
using namespace std;


void brute(int a[],int n,int k){
    // store the first k elements in the temp array and shift the remaining elements by k-places to the left. Insert the elements from the temp array to the original array 
    int temp[k];
    int j=0;
    for(int i=0;i<k;i++){
        temp[j++]=a[i];
    }
    for(int i=k;i<n;i++){
        a[i-k]=a[i];
    }
    j=0;
    for(int i=n-k;i<n;i++){
        a[i]=temp[j++];
    }
}



void optimized(int a[],int n,int k){
    // divide the array into two parts of size k and n-k. Reverse both the array seperately. Then reverse the whole array.
    k=k%n;
    reverse(a,a+k);
    reverse(a+k,a+n);
    reverse(a,a+n);
}


int main(){
    int a[]={1,2,3,4,5,6,7,8,9};
    int n=9;
    int k=4;
    optimized(a,n,k);
    cout<<"Left Rotated Array: ";
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}

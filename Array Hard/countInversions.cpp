#include<bits/stdc++.h>
using namespace std;


void brute(int a[],int n){
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]) count++;
        }
    }
    cout<<"Inversions are: "<<count<<endl;
}



int merge(int a[],int s,int e){
    int count=0;
    int mid=(s+e)/2;
    int size1=mid-s+1;
    int size2=e-mid;
    int arr1[size1];
    int arr2[size2];
    int index=s;
    for(int i=0;i<size1;i++){
        arr1[i]=a[index++];
    }
    for(int i=0;i<size2;i++){
        arr2[i]=a[index++];
    }
    int i=0,j=0;
    index=s;
    while(i<size1 && j<size2){
        if(arr1[i]<=arr2[j]){
            a[index++]=arr1[i++];
        }else{
            a[index++]=arr2[j++];
            count+=mid-s+1-i;
        }
    }
    while(i<size1){
        a[index++]=arr1[i++];
    }
    while(j<size2){
        a[index++]=arr2[j++];
    }
    return count;
}



int mergeSort(int a[],int s,int e){
    int count=0;
    if(s>=e) return count;
    int mid=(s+e)/2;
    count += mergeSort(a,s,mid);
    count += mergeSort(a,mid+1,e);
    count += merge(a,s,e);
    return count;
}



void optimized(int a[],int n){
    // using merge sort to count inversions.
    cout<<"Inversions are: "<< mergeSort(a,0,n-1)<<endl;
}



int main(){
    // given an array, count pairs in which i<j && a[i]>a[j] in all sub-arrays.
    int a[]={5,3,2,4,1};
    int n=5;

    brute(a,n);
    optimized(a,n);
    return 0;
}
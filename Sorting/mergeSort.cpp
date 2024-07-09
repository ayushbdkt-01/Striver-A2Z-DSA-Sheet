#include<bits/stdc++.h>
using namespace std;


void merge(int a[],int s,int e){
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
        }
    }
    while(i<size1){
        a[index++]=arr1[i++];
    }
    while(j<size2){
        a[index++]=arr2[j++];
    }
}


void mergeSort(int a[],int s,int e){
    if(s>=e) return;
    int mid=(s+e)/2;
    mergeSort(a,s,mid);
    mergeSort(a,mid+1,e);
    merge(a,s,e);
}


int main(){
    int a[]={1,3,4,2,8885,8,6,7};
    int n=8;

    mergeSort(a,0,n-1);
    
    cout<<"Sorted array: ";
    for(int i=0;i<=n-1;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
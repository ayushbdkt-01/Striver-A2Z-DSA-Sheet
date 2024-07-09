#include<bits/stdc++.h>
using namespace std;




int partition(int a[],int n,int s,int e){
    int pivot=a[s];
    int count=0;
    for(int i=s+1;i<=e;i++){
        if(a[i]<=pivot) count++;
    }
    int pivotIndex=s+count;
    swap(a[s],a[pivotIndex]);
    int i=s;
    int j=e;
    while(i<pivotIndex && j>pivotIndex){
        while(a[i]<=a[pivotIndex]) i++;
        while(a[j]>a[pivotIndex]) j--;
        if(i<pivotIndex && j>pivotIndex) swap(a[i],a[j]);
    }
    return pivotIndex;
}



void quickSort(int a[],int n,int s,int e){
    if(s>=e){
        return;
    }
    int p=partition(a,n,s,e);
    quickSort(a,n,s,p-1);
    quickSort(a,n,p+1,e);
}



int main(){
    int a[]={1,3,5,2,4,7,6,9,8};
    int n=9;
    quickSort(a,n,0,n-1);
    cout<<"Sorted array: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
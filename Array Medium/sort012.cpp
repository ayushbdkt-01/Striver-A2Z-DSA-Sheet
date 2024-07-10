#include<bits/stdc++.h>
using namespace std;


void brute(int a[],int n){
    // simply sort the array
    sort(a,a+n);
    cout<<"Sorted: ";
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
}



void better(int a[],int n){
    // store the freq of 0 1 and 2 and insert 0 1 2 by reducing the freq until it becomes zero.
    int countZero=0;
    int countOne=0;
    int countTwo=0;
    for(int i=0;i<n;i++){
        if(a[i]==0) countZero++;
        else if(a[i]==1) countOne++;
        else countTwo++;
    }

    for(int i=0;i<n;i++){
        if(countZero != 0) {
            a[i]=0;
            countZero--;
        }
        else if(countOne != 0){
            a[i]=1;
            countOne--;
        } 
        else{
            a[i]=2;
            countTwo--;
        } 
    }
    cout<<"Sorted: ";
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
}



void optimized(int a[],int n){
    // Dutch National Flag Algorithm = 3 Pointer approach =  3 pointers as low mid and high. 
    // zeros from 0 to low-1
    // ones from low to mid-1
    // ** mid to high is the unsorted array.
    // twos from high+ to n-1

    int low=0;
    int mid=0;
    int high=n-1;
    while(mid<high){
        if(a[mid]==0){
            swap(a[low],a[mid]);
            low++,mid++;
        }
        else if(a[mid]==1){
            mid++;
        }
        else if(a[mid]==2){
            swap(a[mid],a[high]);
            high--;
        }
    }
    cout<<"Sorted: ";
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
}


int main(){
    int a[]={1,0,2,2,2,1,1,0,0,0,1,2,2,1,1,1,};
    int n=sizeof(a)/sizeof(a[0]);

    brute(a,n);
    better(a,n);
    optimized(a,n);
    return 0;
}
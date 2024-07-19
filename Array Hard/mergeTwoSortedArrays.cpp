#include<bits/stdc++.h>
using namespace std;


void brute(int a[],int b[],int n1,int n2){
    // Create a new array and store all the elements from the first and second array into the 3rd array in sorted order and then transfer all the elements from the 3rd array to the first and second array respectively.
    int c[n1+n2];
    int i=0,j=0,k=0;
    while(i<n1 && j<n2){
        if(a[i]<=b[j]){
            c[k]=a[i];
            i++,k++;
        }
        else{
            c[k]=b[j];
            k++,j++;
        }
    }
    while(i<n1){
        c[k]=a[i];
        k++,i++;
    }
    while(j<n2){
        c[k]=b[j];
        k++,j++;
    }

    int index=0;
    for(int i=0;i<n1;i++){
        a[i]=c[index];
        index++;
    }
    for(int i=0;i<n2;i++){
        b[i]=c[index];
        index++;
    }

    cout<<"Final Arrays: "<<endl;;
    for(int i=0;i<n1;i++) cout<<a[i]<<" ";
    cout<<endl;
    for(int i=0;i<n2;i++) cout<<b[i]<<" ";
    cout<<endl<<endl;
}



void optimized(int a[],int b[],int n1,int n2){
    int left=n1-1;
    int right=0;

    while(left>=0 && right<n2){
        if(a[left]>b[right]){
            swap(a[left],b[right]);
            left--,right++;
        }else break;
    }

    sort(a,a+n1);
    sort(b,b+n2);

    cout<<"Final Arrays: "<<endl;;
    for(int i=0;i<n1;i++) cout<<a[i]<<" ";
    cout<<endl;
    for(int i=0;i<n2;i++) cout<<b[i]<<" ";
    cout<<endl<<endl;
}



int main(){
    int a[]={1,3,5,7,9};
    int b[]={0,2,4,6,8};
    int n1=5,n2=5;

    brute(a,b,n1,n2);
    optimized(a,b,n1,n2);

    return 0;
}
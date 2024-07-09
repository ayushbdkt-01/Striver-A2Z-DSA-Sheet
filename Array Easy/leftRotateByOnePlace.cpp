#include<bits/stdc++.h>
using namespace std;



void leftRotate(int a[],int n){
    // store the first element in temp and shift each element to one place left and finally place first element at the last.
    int temp=a[0];
    for(int i=1;i<n;i++){
        a[i-1]=a[i];
    }
    a[n-1]=temp;
}



int main(){
    int a[]{1,2,3,4,5};
    int n=5;

    leftRotate(a,n);
    cout<<"After 1 left rotation: ";
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;



void rightRotate(int a[],int n,int k){
    int ans[n];
    for(int i=0;i<n;i++){
        ans[(i+k)%n]=a[i];
    }

    cout<<"After 'k' left rotation: ";
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    cout<<endl;
}



int main(){
    int a[]{1,2,3,4,5};
    int n=5;
    int k=2;

    rightRotate(a,n,k);

    return 0;
}
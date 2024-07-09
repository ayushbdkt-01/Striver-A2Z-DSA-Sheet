#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[]={1,3,4,2,5};
    int n=5;

    for(int i=0;i<=n-2;i++){
        int mini=i;
        for(int j=i+1;j<=n-1;j++){
            if(a[j]<a[mini]){
                mini=j;
            }
        }
        swap(a[i],a[mini]);
    }

    cout<<"Sorted array: ";
    for(int i=0;i<=n-1;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
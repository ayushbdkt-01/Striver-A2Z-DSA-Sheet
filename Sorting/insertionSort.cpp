#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[]={1,3,4,2,5,8,6,7};
    int n=8;


    for(int i=0;i<=n-1;i++){
        for(int j=i;j>0;j--){
            if(a[j]<a[j-1]){
                swap(a[j],a[j-1]);
            }
        }
    }

    
    cout<<"Sorted array: ";
    for(int i=0;i<=n-1;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
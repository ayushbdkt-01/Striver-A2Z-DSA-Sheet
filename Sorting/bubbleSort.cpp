#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[]={1,3,4,2,5,8,6,7};
    int n=8;


    for(int i=n-1;i>=0;i--){
        bool flag=false;
        for(int j=0;j<=i-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                flag=true;
            }
        }
        if(flag==false){
            break;
        }
    }

    
    cout<<"Sorted array: ";
    for(int i=0;i<=n-1;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
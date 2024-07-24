#include<bits/stdc++.h>
using namespace std;



void brute(int a[],int n){
    int single=-1;
    if(n==1){
        single=a[0];
        cout<<"Single element is: "<<single<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        if(i==0){
            if(a[i]!=a[i+1]){
                single=a[i];
                break;
            }
        }
        else if(i==n-1){
            if(a[i]!=a[i-1]){
                single=a[i];
                break;
            }
        }
        else{
            if(a[i]!=a[i+1] && a[i]!=a[i-1]){
                single=a[i];
                break;
            }
        }
    }
    cout<<"Single element is: "<<single<<endl;
}



void optimal(int a[],int n){
    int single=-1;
    if(n==1){
        single=a[0];
        cout<<"Single element is: "<<single<<endl;
        return;
    }
    if(a[0]!=a[1]){
        single=a[0];
        cout<<"Single element is: "<<single<<endl;
        return;
    }
    if(a[n-1]!=a[n-2]){
        single=a[n-1];
        cout<<"Single element is: "<<single<<endl;
        return;
    }
    int s=1,e=n-2;
    while(s<=e){
        int mid=(s+e)/2;
        if(a[mid]!=a[mid-1] && a[mid]!=a[mid+1]){
            single=a[mid];
            break;
        }
        else if( (mid%2==0 && a[mid]==a[mid+1]) || (mid%2==1 && a[mid]==a[mid-1]) ){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    cout<<"Single element is: "<<single<<endl;
}



int main(){
    int a[]={1,1,2,2,3,3,4,5,5,6,6};
    int n=11;

    brute(a,n);  // linear search
    optimal(a,n);  // binary search
    return 0;
}
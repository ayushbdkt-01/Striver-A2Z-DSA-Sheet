#include<bits/stdc++.h>
using namespace std;



int calculate(int a[],int n,int capacity){
    int d=1,load=0;
    for(int i=0;i<n;i++){
        if(load+a[i]>capacity){
            d++;
            load=a[i];
        }else{
            load += a[i];
        }
    }
    return d;
}



void brute(int a[],int n,int days){
    int maxx=*max_element(a,a+n);
    int sumArr=0;
    for(int i=0;i<n;i++){
        sumArr += a[i];
    }

    for(int i=maxx;i<=sumArr;i++){
        int daysRequired=calculate(a,n,i);
        if(daysRequired<=days){
            cout<<"Minimum days are: "<<i<<endl;
            return;
        }
    }
    cout<<"Not Possible"<<endl;
}



void optimal(int a[],int n,int days){
    int maxx=*max_element(a,a+n);
    int sumArr=0;
    for(int i=0;i<n;i++){
        sumArr += a[i];
    }
    int s=maxx,e=sumArr;
    int ans=-1;
    while(s<=e){
        int mid=(s+e)/2;
        int daysRequired=calculate(a,n,mid);
        if(daysRequired<=days){
            ans=mid;
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    cout<<"Minimum days are: "<<ans<<endl;
}



int main(){
    int weight[]={1,2,3,4,5,6,7,8,9,10};
    int n=10;
    int days=5;

    brute(weight,n,days);
    optimal(weight,n,days);
    
    return 0;
}
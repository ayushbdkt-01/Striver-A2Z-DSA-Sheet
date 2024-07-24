#include<bits/stdc++.h>
using namespace std;



bool canPlaceCow(int a[],int n,int distance,int cows){
    int cowCount=1,last=a[0];
    for(int i=1;i<n;i++){
        if(a[i]-last>=distance){
            cowCount++;
            last=a[i];
        }
    }
    if(cowCount>=cows) return true;
    else return false;
}



void brute(int a[],int n,int cows){
    int maxx=*max_element(a,a+n);
    int minn=*min_element(a,a+n);
    for(int i=1;i<maxx-minn;i++){
        if(canPlaceCow(a,n,i,cows)==true) continue;
        else cout<<"Minimum distance is: "<<i-1<<endl;
        return;
    }
}



void optimal(int a[],int n,int cows){
    int maxx=*max_element(a,a+n);
    int minn=*min_element(a,a+n);
    int s=1,e=maxx-minn;
    int ans=-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(canPlaceCow(a,n,mid,cows)==true){
            ans=mid;
            s=mid+1;
        }else{
            e=mid-1;
        }
    }
    cout<<"Minimum distance is: "<<ans<<endl;
}



int main(){
    int a[]={0,3,4,7,9,10};
    int n=6;
    int cows=4;

    brute(a,n,cows);
    optimal(a,n,cows);
    return 0;
}
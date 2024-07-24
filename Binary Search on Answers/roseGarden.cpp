#include<bits/stdc++.h>
using namespace std;



bool possible(int a[],int n,int day,int m,int k){
    int count=0;
    int bouquets=0;
    for(int i=0;i<n;i++){
        if(a[i]<=day) count++;
        else{
            bouquets += count/k;
            count=0;
        }
    }
    bouquets += count/k;
    if(bouquets>=m) return true;
    else return false;
}



void brute(int a[],int n,int m,int k){
    if(m*k>n){ // not enough flowers
        cout<<"Not possible"<<endl;
        return;
    }
    int minn=*min_element(a,a+n);
    int maxx=*max_element(a,a+n);

    for(int i=minn;i<=maxx;i++){
        if(possible(a,n,i,m,k)==true){
            cout<<"Answer is: "<<i<<endl;
            return;
        }
    }
    cout<<"Answer is: "<<-1<<endl;
}




void optimal(int a[],int n,int m,int k){
    if(m*k>n){ // not enough flowers
        cout<<"Not possible"<<endl;
        return;
    }
    int minn=*min_element(a,a+n);
    int maxx=*max_element(a,a+n);

    int s=minn,e=maxx;
    int ans=-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(possible(a,n,mid,m,k)==true){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    cout<<"Answer is: "<<ans<<endl;
}




int main(){
    // given arr[] which represent the blooming time of a flower. Find the minimum number of days so that to fill 'm' bouquets with 'k' adjacent flowers.
    int bloomDay[]={7,7,7,7,13,11,12,7};
    int n=8;
    int m=2;
    int k=3;

    brute(bloomDay,n,m,k);
    optimal(bloomDay,n,m,k);

    return 0;
}
#include<bits/stdc++.h>
using namespace std;



int calculateTime(int a[],int bananasPerHour,int n){
    int ans=0;
    for(int i=0;i<n;i++){
        ans += ceil((double)a[i]/(double)bananasPerHour);
    }
    return ans;
}



void brute(int a[],int n,int maxHours){
    int maxElement=*max_element(a,a+n);
    for(int i=1;i<=maxElement;i++){
        int totalTime=calculateTime(a,i,n);
        if(totalTime<=maxHours){
            cout<<"Koko needs to eat "<<i<<" bananas per hour"<<endl;
            return;
        }
    }
    cout<<"KOKO bhuka marr gya"<<endl;
}




void optimal(int a[],int n,int maxHours){
    // range of answer is from 1 to max_element(arr)
    int ans=INT_MAX;
    int s=1,e=*max_element(a,a+n);
    while(s<=e){
        int mid=(s+e)/2;
        int totalTime=calculateTime(a,mid,n);
        if(totalTime<=maxHours){
            ans=mid;
            e=mid-1;
        }else {
            s=mid+1;
        }
    }
    cout<<"Koko needs to eat "<<ans<<" bananas per hour"<<endl;
}



int main(){
    // given an array of piles in which piles[i] denotes the number of bananas in the i'th pile.
    // Given 'h'(maxHours) time to eat all bananas from all the piles.
    // Find the minimum number of bananas to eat per hour to finish all bananas from each pile.
    int piles[]={3,6,7,11};
    int n=4;
    int maxHours=8;

    brute(piles,n,maxHours); // Linear search
    optimal(piles,n,maxHours); // Binary search

    return 0;
}
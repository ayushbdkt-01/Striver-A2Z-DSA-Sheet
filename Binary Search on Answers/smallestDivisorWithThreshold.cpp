#include<bits/stdc++.h>
using namespace std;




void brute(int a[],int n,int threshold){
    if(threshold<n){
        cout<<"Not possible"<<endl;
        return;
    }
    int maxx=*max_element(a,a+n);

    for(int i=1;i<maxx;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            sum += ceil(double(a[j])/(double)i);
        }
        if(sum<=threshold){
            cout<<"Minimum divisor is: "<<i<<endl;
            return;
        }
    }
    cout<<"Not possible"<<endl;
}



void optimal(int a[],int n,int threshold){
    if(threshold<n){
        cout<<"Not possible"<<endl;
        return;
    }
    int maxx=*max_element(a,a+n);
    int s=1,e=maxx;
    int ans=maxx;
    while(s<=e){
        int mid=(s+e)/2;
        int sum=0;
        for(int i=0;i<n;i++){
            sum += ceil(double(a[i])/(double)mid);
        }
        if(sum<=threshold){
            ans=mid;
            e=mid-1;
        }
        else s=mid+1;
    }
    cout<<"Minimum divisor is: "<<ans<<endl;
}




int main(){
    int a[]={1,2,5,9};
    int n=4;
    int threshold=6;

    brute(a,n,threshold);
    optimal(a,n,threshold);
    return 0;
}
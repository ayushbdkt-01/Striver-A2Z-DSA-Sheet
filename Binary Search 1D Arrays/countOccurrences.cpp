#include<bits/stdc++.h>
using namespace std;


int firstOcc(int a[],int n,int target){
    int s=0,e=n-1;
    int first=-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(a[mid]==target){
            first=mid;
            e=mid-1;
        }
        else if(a[mid]<target) s=mid+1;
        else e=mid-1;
    }
    return first;
}



int lastOcc(int a[],int n,int target){
    int s=0,e=n-1;
    int last=-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(a[mid]==target){
            last=mid;
            s=mid+1;
        }
        else if(a[mid]<target) s=mid+1;
        else e=mid-1;
    }
    return last;
}



int main(){
    int a[]={1,2,3,4,5,5,5,5,6,7,8,9};
    int n=12;
    int target=5;

    int first=firstOcc(a,n,target);
    int last=lastOcc(a,n,target);

    cout<<"Occurrences of target are: "<<last-first+1<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;


void brute(int a[],int n,int target){
    // linear search to find the first and last occurrence of the target.
    int first=-1;
    int last=-1;
    for(int i=0;i<n;i++){
        if(a[i]==target){
            if(first==-1) first=i;
            last=i;
        }
    }
    cout<<"First Occurrence at index: "<<first<<endl;
    cout<<"Last Occurrence at index: "<<last<<endl;
    cout<<endl;
}



void optimal1(int a[],int n,int target){
    // binary search to find the first and last occurrence of the target. Using the concept of lowerBound and upperBound.

    int lb=lower_bound(a,a+n,target) - a;
    int ub=upper_bound(a,a+n,target) - a;

    if(lb==n || a[lb]!=target){
        cout<<"First Occurrence at index: "<<-1<<endl;
        cout<<"Last Occurrence at index: "<<-1<<endl;
        return;
    }
    cout<<"First Occurrence at index: "<<lb<<endl;
    cout<<"Last Occurrence at index: "<<ub-1<<endl;
    cout<<endl;
}



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



void optimal2(int a[],int n,int target){
    //Plain Binary Search to find the first and last occurrence of target.

    int first=firstOcc(a,n,target);
    int last=lastOcc(a,n,target);

    cout<<"First Occurrence at index: "<<first<<endl;
    cout<<"Last Occurrence at index: "<<last<<endl;
    cout<<endl;
}



int main(){
    int a[]={1,2,3,4,5,5,5,6,7,8,9};
    int n=11;
    int target=5;

    brute(a,n,target);
    optimal1(a,n,target);
    optimal2(a,n,target);
    return 0;
}
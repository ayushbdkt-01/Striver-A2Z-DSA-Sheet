#include<bits/stdc++.h>
using namespace std;



void optimal(int a[],int n,int target){
    int s=0,e=n-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(a[mid]==target){
            cout<<"Found at index: "<<mid<<endl;
            return;
        }
        if(a[s]<=a[mid]){  // left sorted
            if(target>=a[s] && target<=a[mid]){ // if target exists on left sorted half.
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        else{  // right sorted
            if(target>=a[mid] && target<=a[e]){ // if target exists on right sorted half.
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
    }
    cout<<"Not Found"<<endl;
}



int main(){
    int a[]={5,6,7,8,1,2,3,4};
    int n=8;
    int target=8;

    optimal(a,n,target);
    return 0;
}
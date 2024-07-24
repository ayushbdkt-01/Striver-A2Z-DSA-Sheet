#include<bits/stdc++.h>
using namespace std;



void optimal(int a[],int n,int target){
    int s=0,e=n-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(a[mid]==target) {
            cout<<"Found at index: "<<mid<<endl;
            return;
        }
        if(a[s]==a[mid] && a[mid]==a[e]){  // duplicate element handling
            s++,e--;
            continue;
        }
        if(a[s]<=a[mid]){  // left sorted
            if(target>=a[s] && target<=a[mid]) e=mid-1;
            else s=mid+1;
        }
        else{ // right sorted
            if(target>=a[mid] && target<=a[e]) s=mid+1;
            else e=mid-1;
        }
    }
    cout<<"Not Found"<<endl;
}



int main(){
    // duplicate elements are present.
    int a[]={3,1,2,3,3,3,3};
    int n=7;
    int target=3;

    optimal(a,n,target);
    return 0;
}
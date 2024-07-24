#include<bits/stdc++.h>
using namespace std;



void brute(int a[],int b[],int n1,int n2,int kth){
    int n=n1+n2;
    int c[n];
    int i=0,j=0,k=0;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            c[k]=a[i];
            i++,k++;
        }else{
            c[k]=b[j];
            j++,k++;
        }
    }
    while(i<n1){
        c[k]=a[i];
        i++,k++;
    }
    while(j<n2){
        c[k]=b[j];
        j++,k++;
    }
    int count=1;
    for(int i=0;i<n;i++){
        if(count==kth){
            cout<<"Kth element is: "<<c[i]<<endl;
            return;
        }
        count++;
    }
}



void better(int a[],int b[],int n1,int n2,int kth){
    int n=n1+n2;
    int count=1;
    int i=0,j=0;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            if(count==kth) {
                cout<<"Kth element is: "<<a[i]<<endl;
                return;
            }
            count++,i++;
        }else{
            if(count==kth) {
                cout<<"Kth element is: "<<b[j]<<endl;
                return;
            }
            count++,j++;
        }
    }
    while(i<n1){
        if(count==kth) {
            cout<<"Kth element is: "<<a[i]<<endl;
            return;
        }
        i++,count++;
    }
    while(j<n2){
        if(count==kth) {
                cout<<"Kth element is: "<<b[j]<<endl;
                return;
            }
        count++,j++;
    }
    cout<<"Kth element not found"<<endl;
}



void optimal(int a[],int b[],int n1,int n2,int kth){
    int s=max(kth-n2,0),e=min(kth,n1);
    int left=kth;
    while(s<=e){
        int mid1=(s+e)>>1;
        int mid2=left-mid1;
        // int l1=INT_MIN,l2=INT_MIN;
        // int r1=INT_MAX,r2=INT_MAX;
        // if(mid1<n1) r1=a[mid1];
        // if(mid2<n2) r2=b[mid2];
        // if(mid1-1>=0) l1=a[mid1-1];
        // if(mid2-1>=0) l2=b[mid2-1];
        int l1 = (mid1 == 0) ? INT_MIN : a[mid1 - 1];
        int l2 = (mid2 == 0) ? INT_MIN : b[mid2 - 1];
        int r1 = (mid1 == n1) ? INT_MAX : a[mid1];
        int r2 = (mid2 == n2) ? INT_MAX : b[mid2];
        if(l1<=r2 && l2<=r1){
            cout<<"Kth element is: "<<max(l1,l2)<<endl;
            return;
        }
        else if(l1>l2) e=mid1-1;
        else s=mid1+1;
    }
    cout<<"Kth element not found"<<endl;
}



int main(){
    int evenA[]={1,3,4,7,10,12};
    int evenB[]={2,3,6,15};
    int evenN1=6;
    int evenN2=4;

    int oddA[]={2,3,4};
    int oddB[]={1,3};
    int oddN1=3;
    int oddN2=2;

    int kth=4;

    brute(evenA,evenB,evenN1,evenN2,kth);
    brute(oddA,oddB,oddN1,oddN2,kth);

    better(evenA,evenB,evenN1,evenN2,kth);
    better(oddA,oddB,oddN1,oddN2,kth);

    optimal(evenA,evenB,evenN1,evenN2,kth);
    optimal(oddA,oddB,oddN1,oddN2,kth);

    return 0;
}
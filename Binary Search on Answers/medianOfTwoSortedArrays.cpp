#include<bits/stdc++.h>
using namespace std;

void brute(int a[],int b[],int n1,int n2){
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

    if(n%2==1){
        cout<<"Median is: "<<c[n/2]<<endl;
        return;
    }else{
        cout<<"Median is: "<<(c[n/2]+c[n/2-1])/2.0<<endl;
        return;
    }
}


void better(int a[],int b[],int n1,int n2){
    int n=n1+n2;
    int index1=n/2, index2=n/2-1;
    int elem1=-1,elem2=-1;
    int count=0;
    int i=0,j=0;

    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            if(count==index1) elem1=a[i];
            if(count==index2) elem2=a[i];
            count++,i++;
        }else{
            if(count==index1) elem1=b[j];
            if(count==index2) elem2=b[j];
            count++,j++;
        }
    }
    while(i<n1){
        if(count==index1) elem1=a[i];
        if(count==index2) elem2=a[i];
        count++,i++;
    }
    while(j<n2){
        if(count==index1) elem1=b[j];
        if(count==index2) elem2=b[j];
        count++,j++;
    }
    if(n%2==1){
        cout<<"Median is: "<<elem1<<endl;
        return;
    }else{
        cout<<"Median is: "<<(elem1+elem2)/2.0<<endl;
        return;
    }
}



void optimal(int a[],int b[],int n1,int n2){
    int s=0,e=min(n1,n2);
    int left=(n1+n2+1)/2;
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
            if(mid2-1>=0){
                cout<<"Median is: "<<max(l1,l2)<<endl;
                return;
            }
            else{
                cout<<"Median is: "<<(max(l1,l2)+min(r1,r2))/2.0<<endl;
                return;
            } 
        }
        else if(l1>l2) e=mid1-1;
        else s=mid1+1;
    }
    cout<<"Median is not found"<<endl;
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

    brute(evenA,evenB,evenN1,evenN2);
    brute(oddA,oddB,oddN1,oddN2);

    better(evenA,evenB,evenN1,evenN2);
    better(oddA,oddB,oddN1,oddN2);

    optimal(evenA,evenB,evenN1,evenN2);
    optimal(oddA,oddB,oddN1,oddN2);

    return 0;
}
#include<bits/stdc++.h>
using namespace std;



int better(int a[],int n){
    // find the smallest element and search again for the smallest element which is not equal to the smallest element. This is out second largest element.
    int smallest=a[0];
    for(int i=1;i<n;i++){
        smallest=min(smallest,a[i]);
    }
    int secondSmallest=INT_MAX;
    for(int i=0;i<n;i++){
        if(a[i]!=smallest && a[i]<secondSmallest){
            secondSmallest=a[i];
        }
    }
    return secondSmallest;
}




int brute(int a[],int n){
    // sort the array. first element is the smallest element. traverse from start to end and if any element is not equal to a[0], this is our secondSmallest element.
    sort(a,a+n);
    int smallest=a[0];
    int secondSmallest=INT_MAX;
    for(int i=0;i<n;i++){
        if(a[i]!=smallest){
            secondSmallest=a[i];
            break;
        }
    }
    return secondSmallest;
}



int optimized(int a[],int n){
    // finding the smallest and making the previous smallest as the 2nd smallest. if any element is just smaller the smallest and greater than the secondSmallest, update the second smallest element
    int smallest=a[0];
    int secondSmallest=INT_MAX;
    for(int i=0;i<n;i++){
        if(a[i]<smallest){
            secondSmallest=smallest;
            smallest=a[i];
        }
        else if(a[i]>smallest && a[i]<secondSmallest){
            secondSmallest=a[i];
        }
    }
    return secondSmallest;
}




int main(){
    int a[]={1,1,2,3,6,5,7,7};
    int n=sizeof(a)/sizeof(a[0]);
    
    cout<<"Brute: "<<brute(a,n)<<endl;
    cout<<"Better: "<<better(a,n)<<endl;
    cout<<"Optimized: "<<optimized(a,n)<<endl;



    return 0;
}
#include<bits/stdc++.h>
using namespace std;



int better(int a[],int n){
    // find the largest element and search again for the largest element which is not equal to the largest element. This is out second largest element.
    int largest=a[0];
    for(int i=1;i<n;i++){
        largest=max(largest,a[i]);
    }
    int secondLargest=-1;
    for(int i=0;i<n;i++){
        if(a[i]!=largest && a[i]>secondLargest){
            secondLargest=a[i];
        }
    }
    return secondLargest;
}




int brute(int a[],int n){
    // sort the array. last element is the largest element. traverse from end to start and if any element is not equal to a[n-1], this is out secondLargest element.
    sort(a,a+n);
    int largest=a[n-1];
    int secondLargest=INT_MIN;
    for(int i=n-2;i>=0;i--){
        if(a[i]!=largest){
            secondLargest=a[i];
            break;
        }
    }
    return secondLargest;
}



int optimized(int a[],int n){
    // finding the largest and making the previous largest as the 2nd largest. if any element is just smaller the largest and greater than the secondlargest, update the second largest element
    int largest=a[0];
    int secondLargest=-1;
    for(int i=0;i<n;i++){
        if(a[i]>largest){
            secondLargest=largest;
            largest=a[i];
        }
        else if(a[i]<largest && a[i]>secondLargest){
            secondLargest=a[i];
        }
    }
    return secondLargest;
}




int main(){
    int a[]={1,4,2,3,6,5,7,7};
    int n=sizeof(a)/sizeof(a[0]);
    
    cout<<"Brute: "<<brute(a,n)<<endl;
    cout<<"Better: "<<better(a,n)<<endl;
    cout<<"Optimized: "<<optimized(a,n)<<endl;



    return 0;
}
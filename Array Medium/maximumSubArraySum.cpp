#include<bits/stdc++.h>
using namespace std;


void brute(int a[],int n){
    // generate all sub-arrays and find the maximum sum.
    int maxx=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum += a[k];
                maxx=max(maxx,sum);
            }
        }
    }
    cout<<"Maximum Sub-Array Sum is: "<<maxx<<endl;
}



void better(int a[],int n){
    // generate all sub-arrays and find the maximum sum.
    int maxx=INT_MIN;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=a[j];
            maxx=max(maxx,sum);
        }
    }
    cout<<"Maximum Sub-Array Sum is: "<<maxx<<endl;
}



void optimized(int a[],int n){
    // Kadane's Algorithm = maxSum store the maximmum sum ever found and if sum becomes -ve, make the sum as zero.
    int maxSum=a[0];
    int sum=a[0];
    for(int i=1;i<n;i++){
        sum=sum+a[i];
        maxSum=max(sum,maxSum);
        if(sum<0){
            sum=0;
        }
    }
    cout<<"Maximum Sub-Array Sum is: "<<maxSum<<endl;
}



int main(){
    int a[]={1,3,-2,-4,-5,4,2,5};
    int n=8;

    brute(a,n);
    better(a,n);
    optimized(a,n);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;


void brute(int a[],int n,int target){
    // generate all sub-arrays and store the length of the maximum sub-array.
    int len=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum = sum + a[k];
            }
            if(sum==target){
                len=max(len,j-i+1);
            }
        }
    }
    cout<<"Maximum Length: "<<len<<endl;
}



void better(int a[],int n,int target){
     // generate all sub-arrays and store the length of the maximum sub-array.
    int len=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum = sum + a[j];
            if(sum==target){
                len=max(len,j-i+1);
            }
        }
    }
    cout<<"Maximum Length: "<<len<<endl;
}



void better2(int a[],int n,int target){
    // uses hashing to store the prefixSum and if sum==target, update the maxLen and if not, insert the <sum,length> in the map for future use.
    // +ve, -ve and zeros.
    map<int,int> prefixSumMap;
    int sum=0;
    int maxLen=0;
    for(int i=0;i<n;i++){
        sum += a[i];
        if(sum==target)
            maxLen=max(maxLen,i+1);
        int remainingSum=sum-target;
        if(prefixSumMap.find(remainingSum) != prefixSumMap.end()){
            int len=i-prefixSumMap[remainingSum];
            maxLen=max(maxLen,len);
        }
        if(prefixSumMap.find(sum) == prefixSumMap.end())
            prefixSumMap[sum]=i;
    }
    cout<<"Maximum Length: "<<maxLen<<endl;
}



void optimized(int a[],int n,int target){
    // greedy and two-pointer approach. Find the sum to right, if sum==target, then update the maxLen, if sum>target,then decrement the sum from the left.
    // only +ve and zeros.
    int left=0,right=0;
    int maxLen=0;
    int sum=a[0];
    while(right<n){
        while(left<right && sum>target){
            sum -= a[left];
            left++;
        }
        if(sum==target)  maxLen=max(maxLen,right-left+1);
        right++;
        if(right<n)  sum += a[right];
    }
    cout<<"Maximum Length: "<<maxLen<<endl;
}



int main(){
    // given an array and a target sum, find the length of the longest subArray with the target sum.

    int a[]={1,2,3,4,5,5,6,7,8,9,10};
    int n=11;
    int target=5;

    brute(a,n,target);
    better(a,n,target);
    better2(a,n,target);
    optimized(a,n,target);
    myOptimized(a,n,target);

    return 0;
}

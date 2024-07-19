#include<bits/stdc++.h>
using namespace std;


void brute(int a[],int n){
    // count frequency of each element from the array, if freq==2, it's the repeating number, if freq==0, it's the missing number.

    for(int i=1;i<=n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(i==a[j]) count++;
        }
        if(count==0) cout<<"Missing Number: "<<i<<endl;
        if(count==2) cout<<"Repeating Number: "<<i<<endl;
    }
    cout<<endl;
}



void better(int a[],int n){
    // Use hashing to count frequency and then same as brute.

    int hashArr[n+1]={0};
    for(int i=0;i<n;i++) hashArr[a[i]]++;
    for(int i=1;i<n+1;i++){
        if(hashArr[i]==0) cout<<"Missing Number: "<<i<<endl;
        if(hashArr[i]==2) cout<<"Repeating Number: "<<i<<endl;
    }
    cout<<endl;
}



void optimized(int a[],int n){
    // making 2 equations from the observations and solving then will gives us the missing and repeating element.

    // Equation1: Sum of Array elements - Sum of n numbers
    // Equation2: SUm of Square of Array - Sum of square of n numbers.

    int sumN=(n*(n+1))/2;
    int squareN=(n*(n+1)*(2*n+1))/6;

    int sumArr=0;
    int squareArr=0;

    for(int i=0;i<n;i++){
        sumArr += a[i];
        squareArr += a[i]*a[i];
    }
    // solving equations.
    int value1=sumArr-sumN;
    int value2=squareArr-squareN;
    value2=value2/value1;
    int repeating=(value1+value2)/2;
    int missing=repeating-value1;

    cout<<"Repeating Number: "<<repeating<<endl;
    cout<<"Missing Number: "<<missing<<endl;
}



int main(){
    int a[]={4,3,6,2,1,1};
    int n=6;

    brute(a,n);
    better(a,n);
    optimized(a,n);
    return 0;
}
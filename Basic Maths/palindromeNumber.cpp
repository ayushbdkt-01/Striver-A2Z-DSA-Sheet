#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;

    int temp=n;

    int ans=0;
    while(n>0){
        int digit=n%10;
        ans=ans*10+digit;
        n=n/10;
    }

    if(temp==ans){
        cout<<"Number is palindrome"<<endl;
    }else{
        cout<<"Number is not palindrome"<<endl;
    }

    return 0;
}
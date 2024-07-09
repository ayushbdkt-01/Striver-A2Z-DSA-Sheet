#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;

    int sum=0;
    int temp=n;

    while(n>0){
        int digit=n%10;
        sum=sum+(digit*digit*digit);
        n=n/10;
    }

    if(temp==sum){
        cout<<"Number is armstrong"<<endl;
    }else{
        cout<<"Number is not armstrong"<<endl;
    }
    return 0;
}
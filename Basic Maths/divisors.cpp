#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;


    cout<<"Divisors are: ";
    for(int i=1;i<=n;i++){
        if(n%i==0){
            cout<<i<<" ";
        }
    }
    cout<<endl;


    cout<<"Divisors are: ";
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            cout<<i<<" ";
            if(n/i != i){
                cout<<n/i<<" ";
            }
        }
    }


    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;

    int count=0;
    while(n>0){
        count++;
        n=n/10;
    }

    cout<<"Number of digits: "<<count<<endl;
    cout<<"Number of digits: "<<(int)(log10(n)+1)<<endl;

    return 0;
}
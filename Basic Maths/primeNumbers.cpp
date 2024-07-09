#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;


    int count=0;
    for(int i=1;i<=n;i++){
        if(n%i==0){
            count++;
        }
    }
    if(count==2) cout<<"Number is Prime"<<endl;
    else cout<<"Number is not prime"<<endl;



    for(int i=2;i<n;i++){
        if(n%i==0){
            cout<<"Number is not Prime"<<endl;
            return 0;
        }
    }
    cout<<"Number is Prime"<<endl;


    return 0;
}
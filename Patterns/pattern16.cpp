#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        char ch='A';
        for(int j=1;j<=n-i;j++){
            cout<<" ";
        }
        for(int j=1;j<=i;j++){
            cout<<ch<<" ";
            ch++;
        }
        for(char j='A'+i-2;j>='A';j--){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;

    auto gcd=1;
    for(int i=1;i<=min(a,b);i++){
        if(a%i==0 && b%i==0) gcd=i;
    }
    cout<<"Highest Common Factor is: "<<gcd<<endl;


    gcd=1;   // Optimized Method   TC=O(min(a,b))
    for(int i=min(a,b);i>=1;i--){
        if(a%i==0 && b%i==0){
            gcd=i;
            break;
        }
    }
    cout<<"Highest Common Factor is: "<<gcd<<endl;


    
    while(a>0 && b>0){
        if(a>b) a=a-b;
        else b=b-a;
    }
    if(a==0) gcd=b;
    if(b==0) gcd=a;
    cout<<"Highest Common Factor is: "<<gcd<<endl;
    return 0;
}
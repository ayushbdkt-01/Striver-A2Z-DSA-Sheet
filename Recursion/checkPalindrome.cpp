#include<bits/stdc++.h>
using namespace std;


bool checkPal(string str,int s,int e){
    if(s>=e) return true;
    if(str[s]!=str[e]) return false;
    return checkPal(str,s+1,e-1);
}

int main(){
    string s="NAMANn";
    cout<<checkPal(s,0,s.size()-1);
    return 0;
}
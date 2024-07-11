#include<bits/stdc++.h>
using namespace std;



void brute(int a[],int n){
    // insert all the elements in the set and print the set. Can also use an unordered_set to reduce can but answer will not be in sorted order.
    set<int> s;
    for(int i=0;i<n;i++){
        s.insert(a[i]);
    }
    for(auto it: s){
        cout<<it<<" ";
    }
}



int optimized(int a[],int n){
    // i counts the unique elements in the array. if a[i]!=a[j], then increment i and update a[i] for the next iteration.
    sort(a,a+n);
    int i=0;
    for(int j=1;j<n;j++){
        if(a[j]!=a[i]){
            i++;
            a[i]=a[j];
        }
    }
    return i+1;
}



int main(){
    int a[]={1,3,5,4,2,1,3,4,5};
    int n=sizeof(a)/sizeof(a[0]);

    cout<<"Brute:";
    brute(a,n);
    cout<<endl;

    cout<<"Optimized: ";
    cout<<"Size of updated array: "<<optimized(a,n);
   

    return 0;
}

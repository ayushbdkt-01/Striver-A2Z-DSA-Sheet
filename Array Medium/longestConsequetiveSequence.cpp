#include<bits/stdc++.h>
using namespace std;


void brute(int a[],int n){
    // for each current element, search for the current+1 element.
    int longest=1;
    for(int i=0;i<n;i++){
        int current=a[i];
        int count=1;
        while (true) {
            bool found = false;
            for (int j = 0; j < n; j++) {
                if (a[j] == current + 1) {
                    current++;
                    count++;
                    found = true;
                    break;
                }
            }
            if (!found) {
                break;
            }
        }
        longest=max(longest,count);
    }
    cout<<"Longest Consecutive Sequence: "<<longest<<endl;
}



void better(int a[],int n){
    // sort the array and find the largest subsequence
    sort(a,a+n);
    int longest=1;
    int count=1;
    int lastSmaller=a[0];
    for(int i=0;i<n;i++){
        if(a[i]-1==lastSmaller){
            count++;
            lastSmaller=a[i];
        }
        else if(a[i]!=lastSmaller){
            count=1;
            lastSmaller=a[i];
        }
        longest=max(longest,count);
    }
    cout<<"Longest Consecutive Sequence: "<<longest<<endl;
}



void optimized(int a[],int n){
    // use a unordered_set to store all elements and the checking elements in the set.
    unordered_set<int> s;
    int longest=1;
    for(int i=0;i<n;i++){
        s.insert(a[i]);
    }
    for(auto it: s){
        if(s.find(it-1) == s.end()){
            int count=1;
            int x=it;
            while(s.find(x+1) != s.end()){
                x++;
                count++;
            }
            longest=max(longest,count);
        }
    }
    cout<<"Longest Consecutive Sequence: "<<longest<<endl;
}



int main(){
    int a[]={101,4,100,5,102,3,2,1};
    int n=8;

    brute(a,n);
    better(a,n);
    optimized(a,n);
    return 0;
}

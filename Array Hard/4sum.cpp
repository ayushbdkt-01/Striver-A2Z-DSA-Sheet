#include<bits/stdc++.h>
using namespace std;



void brute(int a[],int n,int target){
    for(int i=0;i<n;i++){
        for(int j=i+i;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    if(a[i]+a[j]+a[k]+a[l]==target){
                        cout<<"(Brute) Target is: "<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[l]<<endl;
                    }
                }
            }
        }
    }
}



void better(int a[],int n,int target){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            set<int> hashset;
            for(int k=j+1;k<n;k++){
                int forth=target-(a[i]+a[j]+a[k]);
                if(hashset.find(forth) != hashset.end())
                    cout<<"(Better) Target is: "<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<forth<<endl;
                hashset.insert(a[k]);
            }
        }
    }
}



void optimized(int a[],int n,int target){
    sort(a,a+n);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int k=j+1;
            int l=n-1;
            while(k<l){
                int sum=a[i]+a[j]+a[k]+a[l];
                if(sum==target){
                    cout<<"(Optimized) Target found at: "<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[l]<<endl;
                    k++,l--;
                }
                else if(sum<target){
                    k++;
                }
                else{
                    l--;
                }
            }
        }
    }
}



int main(){
    int a[]{1,2,3,4,5,6,7,8,9};
    int n=9;
    int target=10;

    brute(a,n,target);
    better(a,n,target);
    optimized(a,n,target);
    return 0;
}
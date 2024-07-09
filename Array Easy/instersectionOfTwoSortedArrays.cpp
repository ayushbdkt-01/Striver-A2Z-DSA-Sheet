#include<bits/stdc++.h>
using namespace std;

void brute(int a[],int b[],int n1,int n2){
    // for each element in arr1, check every element of arr2 that it is equal or not and it shouldn't be previously visited. Create a visited[] to check the visited elements of the arr2[].
    int visited[n2]={0};
    vector<int> ans;
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(a[i]==b[j] && visited[j]==0){
                ans.push_back(a[i]);
                visited[j]=1;
            }
        }
    }
    cout<<"Intersection: ";
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<endl;
}



void optimized(int a[],int b[],int n1,int n2){
    // two pointer approach: i at a[0] and j at b[0]. if both elements are equal, push it in the answer array, if greater or smaller, increment i or j accordingly.
    vector<int> ans;
    int i=0,j=0;
    while(i<n1 && j<n2){
        if(a[i]==b[j]){
            ans.push_back(a[i]);
            i++,j++;
        }
        else if(a[i]<b[j]){
            i++;
        }
        else{
            j++;
        }
    }
    cout<<"Intersection: ";
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<endl;

}

int main(){
    int a[]={1,2,3,4,5,6,7};
    int b[]={4,5,6,7,8,9};
    int n1=7;
    int n2=6;
    brute(a,b,n1,n2);
    optimized(a,b,n1,n2);
    return 0;
}
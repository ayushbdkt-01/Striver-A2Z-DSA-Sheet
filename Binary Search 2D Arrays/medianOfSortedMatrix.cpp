#include<bits/stdc++.h>
using namespace std;



void brute(vector<vector<int>> a){
    int row=a.size();
    int col=a[0].size();
    vector<int>arr;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            arr.push_back(a[i][j]);
        }
    }
    sort(arr.begin(),arr.end());
    cout<<"Median is: : "<<arr[arr.size()/2]<<endl;
}



int upperBound(int arr[],int m,int x){
    int s=0;
    int e=m-1;
    int mid=(s+e)/2;
    int ans;
    while(s<=e){
        if(arr[mid]>x){
            ans=mid;
            e=mid-1;
        }
        else s=mid+1;
        mid=(s+e)/2;
    }
    return ans;
}



int func(vector<vector<int>> a,int row,int col,int x){
    int count=0;
    for(int i=0;i<row;i++){
        count += upperBound(a[i],x,col);
    }
    return count;
}



void optimal(vector<vector<int>> a){
    int row=a.size();
    int col=a[0].size();
    int s=INT_MIN,e=INT_MAX;
    int required=(row*col)/2;
    while(s<=e){
        int mid=(s+e)/2;
        int smallEquals=func(a,row,col,mid);
        if(smallEquals<=required) s=mid+1;
        else e=mid-1;
    }
    cout<<"Median is: "<<e<<endl;
}



int main(){
    vector<vector<int>> a={ {1,5,7,9,11},
                            {2,3,4,5,10},
                            {9,10,12,14,16}};
    brute(a);
    optimal(a);
    return 0;
}
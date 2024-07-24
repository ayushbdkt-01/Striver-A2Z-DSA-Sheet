#include<bits/stdc++.h>
using namespace std;



void brute(vector<vector<int>> a,int target){
    int row=a.size();
    int col=a[0].size();
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(a[i][j]==target){
                cout<<"Target at row: "<<i<<" and column: "<<j<<endl;
                return;
            }
        }
    }
    cout<<"Target not found"<<endl;
}




pair<int,int> findTarget(vector<vector<int>> a,int rowNumber,int target){
    int row=a.size();
    int col=a[0].size();

    int s=0,e=col-1;
    pair<int,int> p;
    while(s<=e){
        int mid=(s+e)/2;
        if(a[rowNumber][mid]==target){
            p={rowNumber,mid};
            return p;
        }
        else if(a[rowNumber][mid]<target) s=mid+1;
        else e=mid-1;
    }
    return {-1,-1};
}



void better(vector<vector<int>> a,int target){
    // apply binary search on each row
    int row=a.size();
    int col=a[0].size();

    for(int i=0;i<row;i++){
        if(target>=a[i][0] && target<=a[i][col-1]){
            pair<int,int> p=findTarget(a,i,target);
            if(p.first!=-1) cout<<"Target at row: "<<p.first<<" and column: "<<p.second<<endl;
            else cout<<"Target not found"<<endl;
            return;
        }
    }
    cout<<"Target not found"<<endl;
}


void optimal(vector<vector<int>> a,int target){
    int row=a.size();
    int col=a[0].size();
    int s=0,e=row*col-1;
    while(s<=e){
        int mid=(s+e)/2;
        int rowIndex=mid/col,colIndex=mid%col;
        if(a[rowIndex][colIndex]==target){
            cout<<"Target at row: "<<rowIndex<<" and column: "<<colIndex<<endl;
            return;
        }
        else if(a[rowIndex][colIndex]<target) s=mid+1;
        else e=mid-1;
    }
    cout<<"Target not found"<<endl;
}




int main(){
    // whole matrix is sorted
    vector<vector<int>> a={ {3,  4, 7, 9},
                            {12,13,16,18},
                            {20,21,23,24}};
    
    int target=23;

    brute(a,target);
    better(a,target);
    optimal(a,target);
    return 0;
}
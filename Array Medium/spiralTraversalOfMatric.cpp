#include<bits/stdc++.h>
using namespace std;

void optimized(vector<vector<int>>& matrix){
    int row=matrix.size();
    int col=matrix[0].size();

    int top=0;
    int bottom=row-1;
    int left=0;
    int right=col-1;

    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++){
            cout<<matrix[top][i]<<" ";
        }
        top++;
        for(int i=top;i<=bottom;i++){
            cout<<matrix[i][right]<<" ";
        }
        right--;
        for(int i=right;i>=left && top<=bottom;i--){
            cout<<matrix[bottom][i]<<" ";
        }
        bottom--;
        for(int i=bottom;i>=top && left<=right;i--){
            cout<<matrix[i][left];
        }
        left++;
    }
}


int main(){
    vector<vector<int>> matrix= {{1,2,3,4},
                                {12,13,14,5},
                                {11,16,15,6},
                                {10,9,8,7}};
    
    optimized(matrix);
    return 0;
}
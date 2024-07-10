#include<bits/stdc++.h>
using namespace std;



void brute(vector<vector<int>>& matrix){
    // creating a new array for storing the rotated elements by simple observations.
    int row=matrix.size();
    int col=matrix[0].size();

    int ans[row][col];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            ans[j][row-i-1]=matrix[i][j];
        }
    }

    cout<<"Rotated Array: "<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}


void optimized(vector<vector<int>>& matrix){
    // Firstly, we have to find the transpose of the matrix. Then we have to reverse each and every row by performing these operations. We can rotate a matrix by 90 degree.
    int row=matrix.size();
    int col=matrix[0].size();

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(i<j){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }

    for(int i=0;i<row;i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }

    cout<<"Rotated Array: "<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}



int main(){
    vector<vector<int>> matrix= {{1,2,3,4},
                                {12,13,14,5},
                                {11,16,15,6},
                                {10,9,8,7}};
    
    brute(matrix);
    optimized(matrix);
    return 0;
}
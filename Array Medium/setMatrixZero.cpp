#include<bits/stdc++.h>
using namespace std;

void makeRow(vector<vector<int>>& matrix, int i){
    int row=matrix.size();
    int col=matrix[0].size();
    for(int j=0;j<col;j++){
        matrix[i][j]=-1;
    }
}


void makeCol(vector<vector<int>>& matrix, int j){
    int row=matrix.size();
    int col=matrix[0].size();
    for(int i=0;i<row;i++){
        matrix[i][j]=-1;
    }
}


void brute(vector<vector<int>>& matrix){
    int row=matrix.size();
    int col=matrix[0].size();

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(matrix[i][j]==0){
                makeRow(matrix,i);
                makeCol(matrix,j);
            }
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(matrix[i][j]==-1){
                matrix[i][j]=0;
            }
        }
    }
    cout<<"Modified Matrix: "<<endl;;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<matrix[i][j]<<"  ";
        }
        cout<<endl;
    }
}



void better(vector<vector<int>>& matrix){
    int row=matrix.size();
    int col=matrix[0].size();
    int rowVec[row]={0};
    int colVec[col]={0};

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(matrix[i][j]==0){
                rowVec[i]=1;
                colVec[j]=1;
            }
        }
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(rowVec[i]==1 || colVec[j]==1){
                matrix[i][j]=0;
            }
        }
    }

    cout<<"Modified Matrix: "<<endl;;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<matrix[i][j]<<"  ";
        }
        cout<<endl;
    }
}

int main(){
    vector<vector<int>> matrix= {{1,1,1,1},
                                {1,0,1,1},
                                {1,1,0,1},
                                {1,1,0,1}};
    
    brute(matrix);
    better(matrix);
    return 0;
}
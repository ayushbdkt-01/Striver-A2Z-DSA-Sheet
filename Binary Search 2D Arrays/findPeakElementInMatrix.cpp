#include<bits/stdc++.h>
using namespace std;



void brute(vector<vector<int>> a){
    int maxElement=-1;
    int rowIndex=-1,colIndex=-1;

    int row=a.size();
    int col=a[0].size();

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(a[i][j]>maxElement){
                maxElement=a[i][j];
                rowIndex=i;
                colIndex=j;
            }
        }
    }
    cout<<"Peak element is at row: "<<rowIndex<<" and at column: "<<colIndex<<endl;
}




int findMaxElement(vector<vector<int>> a,int column){
    int row=a.size();
    int maxElement=INT_MIN;
    int maxIndex=-1;
    for(int i=0;i<row;i++){
        if(a[i][column]>maxElement){
            maxElement=a[i][column];
            maxIndex=i;
        }
    }
    return maxIndex;
}



void optimal(vector<vector<int>> a){
    int row=a.size();
    int col=a[0].size();
    int s=0,e=col-1;
    while(s<=e){
        int mid=(s+e)/2;
        int rowNumber=findMaxElement(a,mid);
        int left = mid-1>=0 ? a[rowNumber][mid-1] : -1;
        int right = mid+1<col ? a[rowNumber][mid+1] : -1;
        if(a[rowNumber][mid]>left && a[rowNumber][mid]>right){
            cout<<"Peak element is at row: "<<rowNumber<<" and at column: "<<mid<<endl;
            return;
        }
        else if(a[rowNumber][mid]<left) e=mid-1;
        else s=mid+1;
    }
    cout<<"Peak element not found"<<endl;
}




int main(){
    // whole matrix is sorted. There may be many peak elements, return indexes of any one of them.
    vector<vector<int>> a={ {4,2,5,1,4,5},
                            {2,9,3,2,3,2},
                            {1,7,6,0,1,3},
                            {3,6,2,3,7,2}};
    

    brute(a);
    optimal(a);
    return 0;
}
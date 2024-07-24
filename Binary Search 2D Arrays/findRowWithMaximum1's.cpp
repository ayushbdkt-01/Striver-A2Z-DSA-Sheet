#include<bits/stdc++.h>
using namespace std;



void brute(vector<vector<int>> a){
    int row=a.size();
    int col=a[0].size();
    int rowIndex=-1;
    int maxCount=0;
    for(int i=0;i<row;i++){
        int count=0;
        for(int j=0;j<col;j++){
            count+=a[i][j];
            if(count>maxCount){
                maxCount=count;
                rowIndex=i;
            }
        }
    }
    cout<<"The maximum row with 1's is: "<<rowIndex<<endl;
}



int firstOccurrenceOfOne(vector<vector<int>> a,int rowNumber,int target){
    int row=a.size();
    int col=a[0].size();
    int s=0,e=col-1;
    int index=-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(a[rowNumber][mid]==target){
            index=mid;
            e=mid-1;
        }
        else if(a[rowNumber][mid]==0){
            s=mid+1;
        }
    }
    return index;
}



void optimal(vector<vector<int>> a){
    int row=a.size();
    int col=a[0].size();
    int rowIndex=-1;
    int maxCount=0;
    for(int i=0;i<row;i++){
        int firstOcc=firstOccurrenceOfOne(a,i,1);
        if(firstOcc!=-1){
            int count=col-firstOcc;
            if(count>maxCount){
                maxCount=count;
                rowIndex=i;
            }
        }
    }
    cout<<"The maximum row with 1's is: "<<rowIndex<<endl;

}



int main(){
    // only rows are sorted.
    vector<vector<int>> a={ {0,0,1,1,1},
                            {0,0,0,0,0},
                            {0,1,1,1,1},
                            {0,0,0,0,0},
                            {0,1,1,1,1}};
    brute(a);
    optimal(a);
    return 0;
}
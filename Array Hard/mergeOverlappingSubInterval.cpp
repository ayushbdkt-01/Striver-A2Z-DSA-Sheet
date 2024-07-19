#include<bits/stdc++.h>
using namespace std;

void brute(vector<vector<int>> &v){
    sort(v.begin(),v.end());
    vector<vector<int>> ans;
    for(int i=0;i<v.size();i++){
        int start=v[i][0];
        int end=v[i][1];
        if(ans.size()!=0 && start<ans.back()[1]) continue;
        for(int j=i+1;j<v.size();j++){
            if(v[j][0]<=end) end=max(end,v[j][1]);
            else break;
        }
        ans.push_back({start,end});
    }

    cout<<"Overlapping Intervals are: "<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
}


void optimized(){
    // baad m krunga !!!
}


int main(){
    vector<vector<int>> v={{1,3},{2,6},{8,9},{9,11},{8,10},{2,4},{15,18},{16,17}};

    brute(v);
    return 0;
}
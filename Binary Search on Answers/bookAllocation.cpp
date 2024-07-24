#include<bits/stdc++.h>
using namespace std;



int func(int a[],int n,int pages){
    int studentsCount=1,pagePerStudent=0;
    for(int i=0;i<n;i++){
        if(a[i]+pagePerStudent<=pages) pagePerStudent+=a[i];
        else{
            studentsCount++;
            pagePerStudent=a[i];
        }
    }
    return studentsCount;
}



void brute(int a[],int n,int students){
    if(students>n){
        cout<<"Not possible"<<endl;
        return;
    }
    int sum=0;
    for(int i=0;i<n;i++) sum+=a[i];
    int maxx=*max_element(a,a+n);
    for(int pages=maxx;pages<=sum;pages++){
        int countStudents=func(a,n,pages);
        if(countStudents==students){
            cout<<"Minimum pages are: "<<pages<<endl;
            return;
        }
    }
    cout<<"Not possible"<<endl;
}



void optimal(int a[],int n,int students){
    if(students>n){
        cout<<"Not possible"<<endl;
        return;
    }
    int sum=0;
    for(int i=0;i<n;i++) sum+=a[i];
    int maxx=*max_element(a,a+n);
    int ans=-1;
    int s=maxx,e=sum;
    while(s<=e){
        int mid=(s+e)/2;
        int countStudents=func(a,n,mid);
        if(countStudents>students) s=mid+1;
        else{
            ans=mid;
            e=mid-1;
        }
    }
    cout<<"Minimum pages are: "<<ans<<endl;
}



int main(){
    int a[]={25,46,28,49,24};
    int n=5;
    int students=4;

    brute(a,n,students);
    optimal(a,n,students);

    return 0;
}
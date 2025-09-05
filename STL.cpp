#include<bits/stdc++.h>
using namespace std;



void explainPairs(){
    pair<int,int> p={1,2};
    cout<<p.first<<"  "<<p.second<<endl;

    pair<int,pair<int,int>> pp={1,{1,2}};
    cout<<pp.first<<"  "<<pp.second.first<<"  "<<pp.second.second<<endl;

    pair<int,int> arr[]={{1,2},{3,4},{5,6},{7,8}};
    cout<<"Printing array of pairs: "<<endl;
    for(int i=0;i<4;i++) cout<<arr[i].first<<"  "<<arr[i].second<<endl;
}



void explainVectors(){
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2);
    for(int i=0;i<v.size();i++) cout<<v[i]<<"  ";
    cout<<endl;

    vector<pair<int,string>> vv;
    vv.push_back({1,"Ayush"});
    vv.emplace_back(2,"Bdkt");
    for(int i=0;i<vv.size();i++) cout<<vv[i].first<<"->"<<vv[i].second<<"  ";
    cout<<endl;

    vector<int> vvv(5,1000);
    for(int i=0;i<vvv.size();i++) cout<<vvv[i]<<"  ";
    cout<<endl;

    vector<int> vvvv(7);
    for(int i=0;i<vvvv.size();i++) cout<<vvvv[i]<<"  ";
    cout<<endl;

    vector<int> v2(vvv);
    for(int i=0;i<v2.size();i++) cout<<v2[i]<<"  ";
    cout<<endl;

    vector<int>::iterator it=v.begin();

    cout<<v.size()<<endl; // number of elements
    cout<<v.capacity()<<endl; // allocated space
    cout<<v.empty()<<endl; // true if vector is empty
    v.pop_back(); // removes last element
    cout<<v.front()<<endl; // first element
    cout<<v.back()<<endl; // last element
    v.clear(); // removes all elements 
    v.insert(it,10); // inserts 10 at position it
    v.insert(v.begin()+1,3,40); // inserts value 40, 3 times
    v.insert(v.begin(),v2.begin(),v2.end()); // copies v2 into v at first postion
    v.erase(it); // removes element from position it
    v.erase(v.begin()+2); // deletes element at index 2
    v.erase(v.begin()+1,v.begin()+3); // deletes index 1 and 2
    v.swap(vvv); // swaps 2 vectors

    // 1. Traversal using imdex
    for(int i=0; i<v.size(); i++) cout << v[i] << " ";

    // 2. Using range-based loop
    for(auto x : v) cout << x << " ";

    // 3. Using iterator
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++) cout << *it << " ";

    vector<vector<int>> matrix(3,vector<int>(4,0)); // 3*4 size matrix with all zeros
}



void explainIterators(){
    vector<int> v={1,2,3,4,5,6};

    vector<int>:: iterator it=v.begin(); // pointer to first element
    vector<int>::iterator it2=v.end(); // pointer after last element
    vector<int>::reverse_iterator it3=v.rend(); // pointer before first element
    vector<int>::reverse_iterator it4=v.rbegin(); //pointer to last element

    cout<<*it<<"  ";
    it++;
    cout<<*it<<"  ";
    it++;
    cout<<*it<<"  ";
    it++;
}



void explainLists(){
    list<int> ls={1,2,3}; // implemented as doubley Linked List
    ls.push_back(4);
    ls.emplace_back(5);

    ls.push_front(300); // same as insert() in vector but simple
    ls.emplace_front(400); // same as insert() in vector but simple

    ls.pop_back();
    ls.pop_front();

    // other function are same as vector
}



void explainDeque(){
    deque<int> dq; // doubley ended queue = insertion/deletion from both sides
    dq.push_back(10);
    dq.push_front(20);
    dq.pop_back();
    dq.pop_front();
    dq.front();
    dq.back();
    // other functions are same as list and vector
}



void explainStack(){
    stack<int> st; // last in first out
    st.push(1);
    st.push(2);
    st.push(5);
    cout<<st.top()<<endl;
    // accessing elee=ment is not possible using index
    // can only access the top element using st.top()
    st.pop();// deletes top element
    st.size();
    st.empty();
    stack<int> st1,st2;
    st1.swap(st2); // swapping stacks
    // no other functions in stack
    // every operation takes constant time = O(1)
}



void explainQueue(){
    queue<int> q; // first in first out
    // random access is not possible, only first/last element
    q.push(10);
    q.emplace(20);
    q.pop(); // removes first element
    q.front(); // print first element
    q.back(); // prints last element
    // other operations same as stack
}



void explainPriorityQueue_maxHeap(){
    // largest element stays at top
    // implemented using tree/heap
    // also called max-heap 
    priority_queue<int> pq;
    pq.push(10);
    pq.push(5);
    pq.push(15);
    // elements are stored in ascending order
    pq.top(); // prints the top element = largest element 
    pq.pop(); // removes the top element = largest element
    // push/pop in O(log n)
    // top in O(1)
    // other functions are same as stack/queue;
}




void explainPriorityQueue_minHeap(){
    // smallest element stays at top
    // implemented using tree/heap
    // also called min-heap
    priority_queue<int,vector<int>, greater<int>> pq;
    pq.push(10);
    pq.push(5);
    pq.push(15);
    // elements are stored in descending order
    pq.top(); // prints the top element = smallest element 
    pq.pop(); // removes the top element = smallest element
    // push/pop in O(log n)
    // top in O(1)
    // other functions are same as stack/queue;
}



void explainSet(){
    // every element in sorted(ascending order) and unique order
    set<int> st;
    st.insert(10);
    st.insert(20);
    st.insert(15);
    st.insert(10);
    
    auto it=st.find(15); // gives iterator which points to the address of that element
    // returns st.end() if element is not found

    if(st.find(15)!=st.end()) cout<<"Element Found"<<endl;
    else cout<<"Element not Found"<<endl;

    st.erase(15); // deteles 5 from the set and maintains the sorted order

    st.count(10); // counts how many times element appears, values only 0 and 1 cause set stores only unique elements

    auto it2=st.find(20);
    st.erase(it2);

    auto it3=st.find(3);
    auto it4=st.find(30);
    st.erase(it3,it4); // erases every element in the range 3-29 (last element is not deleted)

    // other functions are same as vector
    // every operation takes O(log n)

    auto it=st.upper_bound(2); // returns pointer which points to the first element >= 2
    auto it=st.lower_bound(3); // returns pointer which points to the first element strictly > 3
    // if no element found, it returns st.end(), TC = O(log n)
}



void explainMuliset(){
    // same as set but stores multiple elements
    // sorted only, not unique
    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(1); // {1,1,1}

    ms.count(1); // count occurrences

    ms.find(1);
    ms.erase(1); // delete all occurrences of 1
    ms.erase(ms.find(1)); // deletes only one occurrence
    // other functions are same as set
}



void explainUnordered_set(){
    // implemented using hashtable (reduces complexity)
    // same as set but not sorted
    // only unique
    // no ordering of elements, random order of elements
    // better complexity than set (except collisions)
    // all functions are same as set (except upper_bound and lower_bound)
    unordered_set<int> st;
    st.insert(10);
    st.insert(10);
    // all functions are in O(1), except the wrost case of hash collosions which is O(n), once in a blue moon
}



void explainMap(){
    // uses key-value pairs (unique keys in sorted order)
    // implemanted using BST
    map<int,int> mpp;
    map<int,pair<int,int>> mpp2;
    map<pair<int,int>,int> mpp3;

    mpp[1]=1;
    mpp.emplace(2,2);
    mpp.insert({3,3});
    mpp3[{10,20}]=30;

    for(auto it: mpp) cout<<it.first<<" --> "<<it.second<<endl;

    cout<<mpp[1]; // if exists, prints the corresponding value to that key
    // if not exists, prints 0 or null

    auto it=mpp.find(100); // if found, points to the that address, if not found, points to mpp.end()
    mpp.lower_bound(2);
    mpp.upper_bound(3);
    // other functions are same as above, erase, size, empty, swap
}



void explainMultimap(){
    // duplicate keys in sorted order
    // other things are same as map
}



void explainUnordered_map(){
    // same as map, but no ordering of keys
    // TC=O(1), wrost case (once in 1 million times) = TC=O(n)
    // wrost case due to hash collisions
}


bool comp(pair<int,int> p1, pair<int,int> p2){
    // sort second element in ascending order
    if(p1.second<p2.second) return true; // correct order
    if(p1.second>p2.second) return false; // swap elements

    // sort first element in descending order
    if(p1.first>p2.first); return true; // do nothing, correct order
    if(p1.first<p2.first); return false; // swap numbers
}


void explainAlgorithms(){

    int a[]={1,2,3,1};
    int n=4;
    sort(a,a+4); // sorting from index 0 to 3 (whole array)
    sort(a+2, a+4); // sorting from index 0 to 3
    sort(a, a+n, greater<int>()); // descending order sorting
    // greater<int> is a built-in comparator 

    pair<int,int> arr[]={{1,2},{2,2},{1,3}};
    // sort in ascending order for 2nd element
    // if 2nd element is same, then sort by first element in descending order
    // we use our own comparator function for custom sorting ("comp")
    // comp is a simple boolean function
    sort(arr,arr+3,comp);

    int num=7;
    int setBitCount=__builtin_popcount(num);

    long long x=123456789;
    int setBitCounts=__builtin_popcountll(x);

    string s="123";
    sort(s.begin(),s.end());
    while(next_permutation(s.begin(),s.end())) cout<<s<<" ";
    // all permutations in dictionary order
    // this only prints the nextPermutaions, not previous ones
    // if we want all permutations, make sure to sort it before printing
    prev_permutation(s.begin(),s.end()); // gives previous permutations

    int maxi=*max_element(a,a+n); // finds largest element in the array
    int mini=*min_element(a,a+n); // finds smallest element in the array

    reverse(a,a+n); // reverses the array

    vector<int> v={1,2,3,4,5};
    int sum=accumulate(v.begin(),v.end(),0); // finds sum of thw whole vector
    int countOfNum=count(v.begin(),v.end(),3); // count occurrence of 3 in the vector
    bool found=binary_search(v.begin(),v.end(), 4); // searches 4 the vector using binary search

    int numOfDigits=log10(1000)+1; // finds number of digits in 1000
}



int main(){
    explainPairs();
    return 0;
}
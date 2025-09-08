

#include <bits/stdc++.h>
using namespace std;
#define lil long long int
const int MOD=1e9+7;

//custom decrement comaparator for map 
class decrease{
    public:
       bool operator()(const int &a,const int &b) const {
           return a>b;
       } 
};


//for increasing order ...reverse for else
struct PairComparator {
    bool operator()(const pair<long long, long long>& a, const pair<long long, long long>& b) const {
        if (a.first != b.first) return a.first > b.first;
        return a.second > b.second;
    }
};

//taking inputs as well
 class comparator{
    public:
    vector<int> &nums;
    comparator( vector<int> &given) :nums(given){}
     bool operator()(int &a,int &b) const {
        if(nums[a]!=nums[b]) return nums[a]>nums[b];
        return a>b;
     }
  };

        comparator comp(nums);
        priority_queue < int,vector<int>,comparator >  q(comp);
//

//stl standard also have 
//min heap 
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;

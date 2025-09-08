//checking a bst or not 
  #include <bits/stdc++.h>
 //check subtree or not
using namespace std;
#define lil long long int
const int MOD=1e9+7;
 #define pb push_back
 #define sort(vec); sort(vec.begin(),vec.end())
#define sort_rev(vec); sort(vec.rbegin(),vec.rend())

//recursive solution doing tle
 class Solution {
public: 
    bool ans=false;
    void solve(vector<int> &freq,int i,vector<int> &quantity){
            if(i==quantity.size()){
             ans=true;
             return;
            }
            int value=quantity[i];
            auto it=lower_bound(freq.begin(),freq.end(),value);
            if(it==freq.end()) return;
            int index=it-freq.begin();
            if(freq[index]==value){
                vector<int> prev=freq;
                freq[index]=0;
                sort(freq);
                solve(freq,i+1,quantity);
                freq=prev;
            }
            else{
                for(int j=index;j<freq.size();j++){
                    vector<int> prev=freq;
                    freq[j]-=value
                    sort(freq);
                    solve(freq,i+1,quantity);
                    freq=prev;
                }
            }
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int,int> hash;
        int n=nums.size();
        for(int i=0;i<n;i++){
           hash[nums[i]]++;
        }
        vector<int> freq;
        for(auto &pair:hash){
            freq.push_back(pair.second);
        }
        sort(freq);
        solve(freq,0,quantity);
        return ans;

    }
};
//recursive solution doing tle
 class Solution {
public: 
     bool solve(vector<int> &freq,int index,vector<int> &quantity){
            if(index==quantity.size()){
             return true;
            }
           for(int i=0;i<freq.size();i++){
            if(freq[i]>=quantity[index]){
              freq[i]-=quantity[index];
              if(solve(freq,index+1,quantity)) return true;
              freq[i]+=quantity[index];
            }
           }
        return false;
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int,int> hash;
        int n=nums.size();
        for(int i=0;i<n;i++){
           hash[nums[i]]++;
        }
        vector<int> freq;
        for(auto &pair:hash){
            freq.push_back(pair.second);
        }
        sort(quantity.rbegin(),quantity.rend());
        return solve(freq,0,quantity);
    }
};
//easirer to understand solution 
int main(){
  vector<int> freq={1,1,3,4,5};
  int value=2;
   auto it=lower_bound(freq.begin(),freq.end(),value);
   cout<<freq[it-freq.begin()];
}
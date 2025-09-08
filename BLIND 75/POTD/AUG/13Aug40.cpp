#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void solve(int index,vector<int>& candidates, int target, vector<int> &current,  vector<vector<int>> &ans){
      int n=candidates.size();
      if(target==0){
        ans.push_back(current);
        return ;
        }
      if(index>=candidates.size()) return ;
      if(target<0) return ;
        //take or not take 
        //not take 
        //if skip
        int j=index+1;
        while(j<n && candidates[j]!=candidates[j-1]) j++;
        if(j<n) solve(j,candidates,target,current,ans);
        //take
        if(candidates[index]<=target){
            current.push_back(candidates[index]);
            solve(index+1,candidates,target-candidates[index],current,ans);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int n=candidates.size();
        vector<int> current;
        sort(candidates.begin(),candidates.end());
        solve(0,candidates,target,current,ans);
        return ans;
    }
};
int main(){
    return 0;
}
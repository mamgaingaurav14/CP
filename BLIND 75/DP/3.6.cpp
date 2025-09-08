#include <bits/stdc++.h>
using namespace std;
//combinational sum
//recursion pure method 1
  vector<vector<int>> recursion (int index,int target,vector<int> &candidates,vector<vector<int>> &answer,vector<int> current){
      int n=candidates.size();
      if(target==0){
        answer.push_back(current);
        return;
      }
      if(index==n) return;
      //not take
      recursion(index+1,target,candidates,answer,current);

      //take
      if(target>=candidates[index]){
        current.push_back(candidates[index]);
        recursion(index,target-candidates[index],candidates,answer,current);
        current.pop_back();
      }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current={};
        vector<vector<int>> answer;
        return recursion(0,target,candidates,answer,current);
    }


//lets try little memorisation
//this is not a dp question rather a recursion only question
//so chill pill

//3some
#include <bits/stdc++.h>
using namespace std;

//method 1 i tried using logic 
//it worked but was slow 
   vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> answer;
        unordered_map<int,int> elements;
        for(int i=0;i<nums.size();i++){
            elements[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
            for (int j=i+1;j<nums.size();j++){
                if(i==j) continue;
                int compliment=0-(nums[i]+nums[j]);
                if(elements.count(compliment)) {
                    if(elements[compliment]==i || elements[compliment]==j) continue;
                    vector<int> option1={nums[i],nums[j],compliment};
                    sort(option1.begin(),option1.end());
                    answer.insert(option1);
                }
            }
        }
        vector<vector<int>> real_answer;
        for(const auto& myvectors:answer){
          real_answer.push_back(myvectors);
        }
        return real_answer;
    }
 int main(){
    for(int i=0;i<6;i++){
        for(int j=i+1;j<6;j++){
            cout<<j<<" ";
            if(i==4) cout<<"last line";
        }
        cout<<endl;
    }
    return 0;
 }

 //most efficient method 
 class Solution {
public:
    //analyzing the 2 pointer approach is very important here 
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> answer;
        for(int i=0;i<nums.size();i++){
            if(i!=0 && nums[i-1]==nums[i]) continue;
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum>0){
                    k--;
                }
                else if(sum<0){
                    j++;
                }
                else{
                  answer.push_back({nums[i],nums[j],nums[k]});
                  j++;
                  k--;
                  while(j<k && nums[j]==nums[j-1]) j++;
                  while(j<k && nums[k]==nums[k+1]) k--;
                }
    }
        }
     return answer;
    }
};

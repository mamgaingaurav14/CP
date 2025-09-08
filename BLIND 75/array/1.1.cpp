#include <bits/stdc++.h>
using namespace std;
    //problem name  2sum

    //method 1 brute force
    //one by one checking and then stopping
    vector<int> twoSum_1(vector<int>& nums, int target) {
       vector<int> answer;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    answer.push_back(i);
                    answer.push_back(j);
                    i=nums.size();
                    break;
                }
            }
        }
        return answer;
    }

    //method 2 optimized
    //using sort
    //good attempt but this doesnt work 

     vector<int> twoSum(vector<int>& nums, int target) {
       vector<int> answer;
        unordered_map<int,int> orginal_indices;
       for(int i=0;i<nums.size();i++){
          orginal_indices[nums[i]]=i;
       }
       sort(nums.begin(),nums.end());
       //nums is sorted 
       int i=0;
       int j=nums.size()-1;
       while(i<j){
         if(nums[i]+nums[j]==target){
            answer.push_back(orginal_indices[nums[i]]);
            answer.push_back(orginal_indices[nums[j]]);
         }
         else if(nums[i]+nums[j]<target){
            i++;
         }
         else{
            j--;
         }
       }
        return answer;
    }

    //method 3
    //lets try working with hash and hash table and see how we go
    /*
    make a hash then start from element no 1 and keep on iteratin
    to check if the pair exist if not then add that element to hash
    else if yes then return that answer only

    hash gyaan
    you can easily find key exist in hash or not using the find
    function but for value you need to iterate over whole hash map
    using 
    for(const auto& pair:hash){
        if(pair.second==value_tofind)
          value found
        else
          not found
    }

    In summary, you use pair.first and pair.second
     when dealing with a std::pair object directly 
     (as in a range-based for loop). You use it->first
      and it->second when dealing with an iterator to a 
      std::pair object (as iterators provide pointer-like
       access to the elements they point to).



    */ 
        vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int,int> hash;
       for(int i=0;i<nums.size();i++){
        auto it=hash.find(target-nums[i]);
        if(it!=hash.end()){
            //found
            return {i,it->second};
        }
            //not found ,then add the value to hash 
            hash[nums[i]]=i;
       }
        return {};
    }
     /*
     you can use either find or count function 
     to check whether a key exist or not*/
     vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (numMap.count(complement)) {
                return {numMap[complement], i};
            }
            numMap[nums[i]] = i;
        }

        return {}; // No solution found
    }
int main(){

}


  #include <bits/stdc++.h>
using namespace std;
//duplicate eleemtnt in arrY
//doesnt work
  bool containsDuplicate(vector<int>& nums) {
        int prod=nums[0];
        for(int i=1;i<nums.size();i++){
          prod=(prod^nums[i]);
        }
        if(prod) return true;
        return false;
    }

  //  method 2 sorting
       bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
           if(nums[i]==nums[i+1]) return true;
        }
        return false;
    }

    //hash map
     //USING HASH MAP APPROACH 
    bool containsDuplicate(vector<int>& nums) {
       unordered_map<int,int> hash;
       for(int i=0;i<nums.size();i++){
        if(hash.find(nums[i])!=hash.end()){
          //if(hash.count(nums[i])){
            ///exist krra hai element
            return true;
        }
        hash[nums[i]]=i;
       }
       return false;
    }

    //there are various different ways possible 
    //hash map where we can calculate the count of 
    //number in array as as wel

//another sexc approach 
bool containsDuplicate(vector<int> nums) {
 
    unordered_set<int> set;
    
    for(int i = 0; i<nums.size();i++){
        set.insert(nums[i]);
    }
    
    // if it contains duplicate then the size of 
    // set will not equal to the length of the array
    if(set.size() < nums.size())
        return true;
    
    return false;
}
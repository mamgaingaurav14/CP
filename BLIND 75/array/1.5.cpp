#include <bits/stdc++.h>
using namespace std;

//max sum subarray problem
 int maxSubArray(vector<int>& nums) {
        int max_sum=INT_MIN;
        int current_sum=0;
        for(int i=0;i<nums.size();i++){
           current_sum=current_sum+nums[i];
           max_sum=max(current_sum,max_sum);
           if(current_sum<0){
            current_sum=0;
           }
        }
        return max_sum;
    }
    //kadane algorithim 
/*
the point is any sum which is less tha 0 will 
always decreasw the sum so we will not include
that function */


//recursion
   int sum(vector<int> &arr ){
        for(int i=0;i<arr.size();i++){
          sum=sum+arr[0];
        }
    }
    void recursion(vector<int> &nums,int current,int &max_sum,int i){
        
    }
    int maxSubArray(vector<int>& nums) {
        int max_sum=0;
        int current=0;
        //nahi lena hai 
        recursion(nums,current,max_sum,i);

        //lena hai 
        recursion(nums,current)
    }
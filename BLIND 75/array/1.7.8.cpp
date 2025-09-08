#include <bits/stdc++.h>
using namespace std;
//min element in a rotated sub array lol 
//search in a sorted rotated arrat using same methods

//dumb way which can be accepted in oa but not in 
//interview
int findMin(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       return nums[0]; 
    }


    //biinary search to find in which wuarter
//min lies
    int findMin(vector<int>& nums) {
       int n=nums.size();
       if(nums[0]<=nums[n-1]) return nums[0];
       int i=1,j=n-1;
       while(i<=j){
        int mid=(i+j)/2;
        if(nums[mid]<=nums[n-1] && nums[mid]<=nums[mid-1]) return nums[mid];
        if(nums[mid]>nums[n-1]){
            //right shift
            i=mid+1;
        }
        else{
          j=mid;
        }
       }
       return -1;
    }
int main(){

}
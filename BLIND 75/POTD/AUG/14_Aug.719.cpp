#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int> &arr,int target){
    int i=0;
    int j=arr.size()-1;
    while(i<=j){
        int mid=i+(j-i)/2;
        if(arr[mid]==target) return true;
        else if(arr[mid]<target){
          i=mid+1;
        }
        else{
            j=mid-1;
        }
    }
    return false;
}
 int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<int> ans;
        for(int i=0;i<n;i++){
            nums[i]=INT_MIN;
            
        }
    }
    int main(){

    }

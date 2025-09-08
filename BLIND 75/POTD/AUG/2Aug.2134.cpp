#include <bits/stdc++.h>
using namespace std;


//brute force naive approach 
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int cnt=0;
       for(int i:nums){
        if(i==1) cnt++;
       }
       int n=nums.size();
       int mini=INT_MAX;
       for(int j=0;j<n;j++){
        //positions to start one
            int swap=0;
            int i=j;
            int temp=cnt;
            int left=n-cnt;
           while(temp--){
             if(nums[i%n]!=1) swap++;
             i++;
            }
            mini=min(swap,mini);
       }
       return mini;
    }
};



//sliding window approach for this subarray problem 
//learnt about mainintaing a window and just adding for subtracitng 
//can be used in many subareay problem 
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        //another opitmized approach 
        
        int n=nums.size();
        queue<int> q;
        int cnt=0;
        for(int i:nums){
          if(i==1) cnt++;
        }
        if(cnt==0) return 0;
        int i=0;
        int temp=cnt;
        int swap=0;
        while(temp--){
            //window ki baat hori hai 
            if(nums[i]==0) swap++;
            q.push(nums[i]);
            i++;
        }
        int mini=swap;
        int temp1=n-1;
        while(temp1--){
           if(q.front()==0) swap--;
           if(nums[i%n]==0) swap++;
           q.pop();
           q.push(nums[i%n]);
           mini=min(swap,mini);
           i++;
        }
     return mini;

    }
};
int main(){

}
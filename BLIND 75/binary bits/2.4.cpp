#include <bits/stdc++.h>
using namespace std;
//find missing no in an array question using xor
  /*
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=((n)*(1+n))/2;
        int diffsum=0;
        for(int i=0;i<nums.size();i++){
          diffsum+=nums[i];
        }
        return sum-diffsum;
    }
     a^0=a;
     a^a=0;

    */
    //method 2 using nxor as we know xor with 0 is same number 
    //and xor with same no is zero
    int missingNumber(vector<int>& nums) {
       int n=nums.size();
       int xo=0;
       for(int i=0;i<nums.size();i++){
          xo^=i^nums[i];
       }
       return xo^n;
    }
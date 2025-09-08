#include <bits/stdc++.h>
using namespace std;

//max product subarray problem

//method 1 brute force in 0(n2);
//tle approach
   int maxProduct(vector<int>& nums) {
        double max_product=INT_MIN;
        for(double i=0;i<nums.size();i++){
            double product=1;
            for(double j=i;j<nums.size();j++){
                product=product*nums[j];
                max_product=max(max_product,product);
            }
        }
        return max_product;
    }
//prefix suffix method is the nicest option 
you must go for 
       int maxProduct(vector<int>& nums) {
        double prefix=1,suffix=1;
        double maxi=INT_MIN;
        double n=nums.size();
        for(int i=0;i<n;i++){
            if(!suffix) suffix=1;
            if(!prefix) prefix=1;
            suffix*=nums[n-i-1];
            prefix*=nums[i];
            maxi=max(maxi,max(prefix,suffix));
        }
        return maxi;
    }


//negative positive approach 
int maxProduct(vector<int>& nums) {
        int product=1;
        int max_product=INT_MIN;
        vector<int> negatives;
        vector<int> max_prods;
        for(int i=0;i<nums.size();i++){
           if(nums[i]>=0){
            product*=nums[i];
           }
           max_product=max(max_product,product);
           else{
            //negative no aa gya hai 
            max_prods.push_back(max_product);
            negatives.push_back(nums[i]);
            product=1;
           }
        }
       int answer=max_product;
          if(!negatives.size()%2){
            //even no of negatives 
           answer=1;
           for(int i=0;i<negatives.size();i++){
            answer*=negatives[i];
           }
           for(int i=0;i<max_prods.size();i++){
            answer*=max_prods[i];
           }
           return answer;
          }
          if(negatives.size()==1) return answer;
         
         
         for(int i=1;i<negatives.size()-1;i++){
            
           }
        
    }

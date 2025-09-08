 #include <bits/stdc++.h>
using namespace std;

//productexceptself question 

//approach 1 ,using divide approach
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod=1;
        vector<int> zero_indices;
        for(int i=0;i<nums.size();i++){
           if(nums[i]==0) {
                zero_indices.push_back(i);
                continue;
            }
           prod=prod*nums[i];
        }
        int n=nums.size();
        vector<int> answer(n,0);
        for(int i=0;i<nums.size();i++){
           if(zero_indices.size()==1){
            //mtlv zero hai ek jagh
            answer[zero_indices[0]]=prod;
            break;
           }
           else if(zero_indices.size()==0){
             answer[i]=prod/nums[i];
           }
        }
        return answer;
    }


//approach 2
/*
baki approaches involves which 
i will do and cover up soon till then wait and watch 
*/


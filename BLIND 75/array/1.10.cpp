/*
conatiner with most water
i have done similar question but the apporach is  abit 
tricky so i have to learn it back 
let me do it later a bit*/

#include <bits/stdc++.h>
using namespace std;

//2 pointer approach 
   /*
   The strategy is to start with the container of 
   the longest width and move the sides inwards one
    by one to see if we can get a larger area by
     shortening the width but getting a taller height. But how do we know which side to move?

The key insight here is that moving the longer side inwards 
is completely unnecessary because the height of the water is
 bounded by the shorter side. In other words, we will never be
  able to get a greater area by moving the longer side inwards 
  because the height will either stay the same or get shorter, and the width will keep decreasing.

So we can skip all those calculations and instead move the shorter
 side inwards. This way, we might get a taller height and a larger 
 area. So at each step, we calculate the area then move the shorter 
 side inwards. When the left and right sides meet, we are done and we
  can return the largest area calculated so far.
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int answer=INT_MIN;
        while(i<j){
           int ans=(j-i)*min(height[i],height[j]);
           answer=max(answer,ans);
           if(height[i]<height[j]){
            i++;
           }
           else{
            j--;
           }
        }
        return answer;
    }
    */

   class Solution {
public:

    //brute force is the must you should learn 
    int maxArea(vector<int>& height) {
        int maxArea=INT_MIN;
        for(int i=0;i<height.size();i++){
            for(int j=i+1;j<height.size();j++){
             int area=min(height[i],height[j])*(j-i);
              maxArea=max(maxArea,area);
            }
        }
        return maxArea;
    }
};
int main(){

}
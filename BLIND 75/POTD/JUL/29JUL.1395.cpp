#include <bits/stdc++.h>
using namespace std;


//tle solution lets optimize this
class Solution {
public:
     int cnt=0;
     void solve_plus(vector<int>& rating,int index,int number,int prev){
        if(number==3){
            cnt++;
            return;
        }
        int n=rating.size();
        if(index==n) return;
        //skip
         solve_plus(rating,index+1,number,prev);
         if(rating[index]>prev)  solve_plus(rating,index+1,number+1,rating[index]);
     }
      void solve_minus(vector<int>& rating,int index,int number,int prev){
        if(number==3){
            cnt++;
            return;
        }
        int n=rating.size();
        if(index==n) return;
        //skip
         solve_minus(rating,index+1,number,prev);
         if(rating[index]<prev)  solve_minus(rating,index+1,number+1,rating[index]);
     }
     
    int numTeams(vector<int>& rating) {
        solve_minus(rating,0,0,INT_MAX);
        solve_plus(rating,0,0,INT_MIN);
        return cnt;
    }
};


//another apporach involing considering 2 left large 
//and right large and small elements

class Solution {
public:
    int numTeams(vector<int>& arr) {
        int n=arr.size();
        int ans=0;
        for(int i=1;i<n-1;i++){
               
            //left
            int left_small=0;
           for(int j=0;j<i;j++){
            if(arr[j]<arr[i]) left_small++;
           }
           int left_large=i-left_small;

           //right
           int right_small=0;
           for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i]) right_small++;
           }
           int right_large=n-i-1-right_small;
           ans+=(left_small*right_large)+ (right_small*left_large);
        }
        return ans;
    }
};


// lets optimize this
class Solution {
public:
     int solve_plus(vector<int>& rating,int index,int cnt, vector<vector<int>> &dp_plus){
        if(cnt==3) return 1;
        if(dp_plus[index][cnt]!=-1) return dp_plus[index][cnt];
        int res=0;
        int n=rating.size();
         for(int i=index+1;i<n;i++){
          if(rating[i]<rating[index]) continue;
          res+=solve_plus(rating,i,cnt+1,dp_plus);
         }
         return dp_plus[index][cnt]=res;
     }
      int solve_minus(vector<int>& rating,int index,int cnt,vector<vector<int>> &dp_minus){
        if(cnt==3) return 1;
        if(dp_minus[index][cnt]!=-1) return dp_minus[index][cnt];
        int res=0;
        int n=rating.size();
         for(int i=index+1;i<n;i++){
          if(rating[i]>rating[index]) continue;
          res+=solve_minus(rating,i,cnt+1,dp_minus);
         }
         return dp_minus[index][cnt]=res;
     }
     
    int numTeams(vector<int>& rating) {
        vector<vector<int>> dp_plus(1000,vector<int> (3,-1));
        vector<vector<int>> dp_minus(1000,vector<int> (3,-1));
        int res=0;
        int n=rating.size();
        for(int i=0;i<n;i++){
            res+=solve_plus(rating,i,1,dp_plus);
            res+=solve_minus(rating,i,1,dp_minus);
        }
        return res;
    }
    
};
int main(){
    return 0;
}
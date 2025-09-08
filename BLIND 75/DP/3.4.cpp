#include <bits/stdc++.h>
using namespace std;
//longest common subsequence 
//plain dry recursion with dp very imp 
class Solution {
public:
     int recursion(int index1,int index2,string &text1, string &text2){
        //base case
        if(index1<0||index2<0) return 0;
        if(text1[index1]==text2[index2]){//matches
            return 1+recursion(index1-1,index2-1,text1,text2);
        }
        else{
         return max(recursion(index1-1,index2,text1,text2),recursion(index1,index2-1,text1,text2));
        }
     }
    int longestCommonSubsequence(string text1, string text2) {
        return recursion(text1.size()-1,text2.size()-1,text1,text2);
    }
};

//with memorisation dp and optimized solution
   int recursion(int index1,int index2,string &text1, string &text2,vector<vector<int>> &dp){
        //base case
        if(index1<0||index2<0) return 0;
        if (dp[index1][index2]!=-1) return dp[index1][index2];
        if(text1[index1]==text2[index2]){//matchesx
            return dp[index1][index2]=1+recursion(index1-1,index2-1,text1,text2,dp);
        }
        else{
         return dp[index1][index2]=max(recursion(index1-1,index2,text1,text2,dp),recursion(index1,index2-1,text1,text2,dp));
        }
     }
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size()-1;
        int n2=text2.size()-1;
         vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        return recursion(n1,n2,text1,text2,dp);
    }

    //bottom to up approach 
     int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for(int index1=0;index1<n1;index1++){
            for(int index2=0;index2<n2;index2++){
               if(text1[index1]==text2[index2]){//matches
                 dp[index1+1][index2+1]=1+dp[index1][index2];
                }
               else{
                dp[index1+1][index2+1]=max(dp[index1][index2+1],dp[index1+1][index2]);
                  } 
           }
        }
        return dp[n1][n2];
    }

    //space optimized approach 
    //prev and current are arrays having values 
    //of second index at prev and current index1
    //tricky to understand but pretty cool
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<int> prev(n2+1,0);
        vector<int> curr(n2+1,0);
        for(int index1=0;index1<n1;index1++){
            for(int index2=0;index2<n2;index2++){
               if(text1[index1]==text2[index2]){//matches
                 curr[index2+1]=1+prev[index2];
                }
               else{
                curr[index2+1]=max(prev[index2+1],curr[index2]);
                  } 
           }
           prev=curr;
        }
        return prev[n2];
    }



int main(){

}
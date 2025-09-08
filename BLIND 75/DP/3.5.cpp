//word break
#include <bits/stdc++.h>
using namespace std;
//recursion without memorisation
/*
 bool linersearch(string s,vector<string>& worDict){
    for(string all:worDict){
        if(s==all) return true;
    }
    return false;
   } 
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        if(n==0) return true;
        for(int i=n-1;i>=0;i--){
            string sub=s.substr(0,i+1);
            if(linersearch(sub,wordDict)){
                string remaining=s.substr(i+1,n-1);
                bool answer= wordBreak(remaining, wordDict);
                if(answer) return true;
            }
        }
        return false;
    }
*/
    //recursion with memo
     bool linearsearch(string s,vector<string>& wordDict){
    for(string all:wordDict){
        if(s==all) return true;
    }
    return false;
   } 
   bool recursion(string s,vector<string>& wordDict,vector<int> &dp,int index){
        int n=s.size();
        if(index==n) return true;//zero length string 
        if (dp[index]!=-1) return dp[index];
        for(int i=n-1;i>=index;i--){
// yahi error hora tha baar baar string sub=s.substr(index,i+1);
          string sub=s.substr(index,i-index+1);
            if(linearsearch(sub,wordDict)){
                bool answer= recursion(s,wordDict,dp,i+1);
                if(answer) return dp[index]=1;
            }
        }
        return dp[index]=0;
   }
    bool wordBreak(string s, vector<string>& wordDict) {
       int n=s.size();
       vector<int> dp(n+1,-1);
       dp[n]=1;
       int index=0;
       return recursion(s,wordDict,dp,index);
    }
int main(){
    string s="catsandog";
    vector<string> wordDict = {"cats","cat","dog","sand"};
    cout<<wordBreak(s,wordDict);

}
//iss question me bht galat kiya apne 
/*
    //chathpt
    bool linearSearch(const string& s, const unordered_set<string>& wordDict) {
    return wordDict.find(s) != wordDict.end();
}

// Optimized wordBreak function with memoization
bool wordBreakHelper(const string& s, const unordered_set<string>& wordDict, vector<int>& memo, int start) {
    int n = s.size();
    if (start == n) return true;
    if (memo[start] != -1) return memo[start];

    for (int end = start + 1; end <= n; ++end) {
        string sub = s.substr(start, end - start);
        if (linearSearch(sub, wordDict) && wordBreakHelper(s, wordDict, memo, end)) {
            return memo[start] = true;
        }
    }
    return memo[start] = false;
}

bool wordBreak(const string& s, const vector<string>& wordDict) {
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    vector<int> memo(s.size(), -1);
    return wordBreakHelper(s, wordSet, memo, 0);
}

*/
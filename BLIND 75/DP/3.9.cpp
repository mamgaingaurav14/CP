//decode ways 
#include <bits/stdc++.h>
using namespace std;
//recursion with memo using lot of memory
  int recursion(int index,string &s,vector<int> dp){
        int n=s.size();
        if(index==n) return 1;
        if(s[index]=='0') return 0;
        if(dp[index]!=-1) return dp[index];
        
        //either individual or group
        int indi=0;
        if((index==n-1 || s[index+1]!='0' )){
            indi=recursion(index+1,s,dp);
        }
        int grpi=0;
        if(index!=n-1){
            string sub=s.substr(index,2);
            if(stoi(sub)<27) grpi=recursion(index+2,s,dp);
        }
        return dp[index]=indi+grpi;
    }

    //dp bottom to up same technique
    int numDecodings(string s) {
        int i=0;
        int n=s.size();
        vector<int> dp(n+1,0);
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
          if(s[i]=='0') dp[i]=0;
          else{
            dp[i]=dp[i+1];
              if(i!=n-1){
                 string sub=s.substr(i,2);
                 if(stoi(sub)<27) dp[i]+=dp[i+2];
                } 
          }
        }
        return s.empty()?0:dp[0];
    }

    //more space optimized
       int numDecodings(string s) {
        int i=0;
        int n=s.size();
        vector<int> dp(n+1,0);
        int p=1;int pp=0;
        for(int i=n-1;i>=0;i--){
          int curr=s[i]=='0'? 0:p;
          if(i<n-1 && (s[i]=='1'||s[i]=='2'&&s[i+1]<'7')) curr+=pp;
          pp=p;
          p=curr;
        }
        return s.empty()?0:p;
    }

int main(){
    //values from 1 to 26
    string s="110";
    string sub=s.substr(0,2);
    cout<<(stoi(sub));
}   
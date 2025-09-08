 #include <bits/stdc++.h>
using namespace std;


//wrong approach 
int minimumDeletions(string s) {
        int cnt=0;
        int first_b;
        int last_a;
        bool flag=true;
        int n=s.size();
        for(int i=0;i<n;i++){
          if(s[i]=='b' && flag){
            first_b=i;
            flag=false;
          }
          if(s[i]=='a') last_a=i;
        }
        if(last_a<first_b) return 0;
        int cnt_a=0;
        int cnt_b=0;
        for(int j=first_b;j<=last_a;j++){
           if(s[j]=='a') cnt_a++;
           else cnt_b++;
        }
        return min(cnt_a,cnt_b);
    }

    //right approach 3 pass approach
    class Solution {
public:
    int minimumDeletions(string s) {
        vector<int> b_before;
        vector<int> a_after;
        int n=s.size();
        int cnt_b=0;
        for(int i=0;i<n;i++){
          b_before.push_back(cnt_b);
          if(s[i]=='b') cnt_b++;
        }
        int cnt_a=0;
        for(int i=n-1;i>=0;i--){
          a_after.push_back(cnt_a);
          if(s[i]=='a') cnt_a++;
        }
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
         mini=min(b_before[i] + a_after[n-i-1],mini);
        }
        return mini;
    }
};

//stack approach 
  //stack approach another one
int minimumDeletions(string s) {
       
        int n=s.size();
        stack <char> st;
        int ans=0;
        for(int i=0;i<n;i++){
          if(!st.empty() &&  st.top()=='b' && s[i]=='a' && ++ans ) st.pop();
          else st.push(s[i]);
        }
        return ans;

    }

    //another approach 
      //inspired from stack approach 
    int minimumDeletions(string s) {
       
        int n=s.size();
        stack <char> st;
        int ans=0;
        int b_count=0;
        for(int i=0;i<n;i++){
          if(b_count>0 && s[i]=='a' && ++ans) b_count--;
          else if(s[i]=='b') b_count++;
        }
        return ans;

    }
    int main(){

    }
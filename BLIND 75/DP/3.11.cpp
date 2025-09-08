#include <bits/stdc++.h>
using namespace std;
//unique paths question

//tabulation apporach direct
 int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0]=1;
           for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //tabulatio is easy bruh just focus on dividing the problems in mulitple subproblems
                //and understanding the approaches use tabulation direcctly agar aa jaye ,agar nhi to 
                //to start from recursion then memorisation then tabultaion;
                //calculate unique paths till that point 
                if(j-1>=0) dp[i][j]=dp[i][j-1];
                if(i-1>=0) dp[i][j]+=dp[i-1][j];
            }
           }

           return dp[m-1][n-1];
    }


//tabultion with SO

//issi ke sath apka hard dp hota hai yaha samapt
//hare krishna
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n,0);
           for(int i=0;i<m;i++){
            vector<int> curr(n,0);
            for(int j=0;j<n;j++){
                if(i==0&&j==0) curr[0]=1;
                if(j-1>=0) curr[j]=curr[j-1];
                if(i-1>=0) curr[j]+=prev[j];
            }
            prev=curr;
           }
           return prev[n-1];
    }
};

int main(){

}
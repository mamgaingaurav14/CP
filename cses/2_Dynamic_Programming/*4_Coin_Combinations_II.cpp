
 //waiting to be solved
#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;

 //removing the long long ints works actually
     //write your code
  int solve(){
      int n,x;
      cin>>n>>x;
   vector<int> arr(n,0);
       for(int i=0;i<n;i++){
          cin>>arr[i];
    }
    vector<vector<int>> dp(x+1,vector<int> (n+1,0));
    for(int a=0;a<=n;a++){
      dp[0][a]=1;
    }
    for(int i=1;i<=x;i++){//sum
      for(int j=n-1;j>=0;j--){//staring from index no
       dp[i][j]=dp[i][j+1];
       if(i<arr[j]) continue;
       dp[i][j]=(dp[i][j]+(dp[i-arr[j]][j]%MOD))%MOD;
       }
        }
   return dp[x][0];
  }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout<<solve();
}
 //better the loop runs in different order of stat 
 
//HARE KRISHNA HARE KRISHNA
//KRISHNA KRISHNA HARE HARE
//HARE RAMA HARE RAMA
#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
#define lil long long int
 
  int solve(){
      int n,x;
      cin>>n>>x;
       vector<int> arr(n);
       for(int i=0;i<n;i++){
           cin>>arr[i];
       }
       vector <vector<int>> dp(n+1,vector<int>(x+1,0));
       for(int i=0;i<=n;i++) dp[i][0]=1;
    for(int i=n-1;i>=0;i--){
       for(int j=1;j<=x;j++){ 
            dp[i][j]=(dp[i+1][j]);
            if(arr[i]<=j) dp[i][j]=(dp[i][j]+dp[i][j-arr[i]])%MOD;
        }
       }
       return (dp[0][x]);
 }
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout<<solve()<<endl;
    
}


// most opitmised
//#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
#define lil long long int
 
  int solve(){
      int n,x;
      cin>>n>>x;
       vector<int> arr(n);
       for(int i=0;i<n;i++){
           cin>>arr[i];
       }
       vector<int> prev(x+1,0);
       prev[0]=1;
    for(int i=n-1;i>=0;i--){
       vector<int> dp(x+1,0);
       dp[0]=1;
       for(int j=1;j<=x;j++){ 
            dp[j]=prev[j];
            if(arr[i]<=j) dp[j]=(dp[j]+dp[j-arr[i]])%MOD;
        }
        prev=dp;
       }
       return prev[x];
 }
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout<<solve()<<endl;
    


}



////why is order of loop important as in 
int solve(){
      int n,x;
      cin>>n>>x;
       vector<int> arr(n);
       for(int i=0;i<n;i++){
           cin>>arr[i];
       }
       vector<int> prev(x+1,0);
       prev[0]=1;
       for(int i=1;i<=x;i++){ 
        vector<int> dp(x+1,0);
        dp[0]=1;
        for(int j=n-1;j>=0;j--){
            dp[i]=prev[i];
            if(arr[j]<=i) dp[i]=(dp[i]+dp[i-arr[j]])%MOD;
        }
        prev=dp;
       }
       return prev[x];
 }
 //becuase above is wrong because of each array should have all [x] vlaues but it doesnt have so ;that is the point 



 
#include <bits/stdc++.h>
using namespace std;
int MOD=1e9+7;
#define lil long long int
 
     //write your code
 lil solve(){
    
      lil n;
      cin>>n;
      lil ans=1;
      while(n--){
        ans=((ans%MOD)* 2)%MOD;
      }
      return ans;
     //write your code
 
 
 
 }
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
   int t=1;
    while(t--){
        solve();
    }
    
}
 
 
//HARE KRISHNA HARE KRISHNA
//KRISHNA KRISHNA HARE HARE
//HARE RAMA HARE RAMA
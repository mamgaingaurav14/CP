
 
#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
#define lil long long int
 
     //write your code
lil solve(){
    
      lil n;
      cin>>n;
      //you will get sifficient 2s's just search 5s 
      lil ans=0;
      lil start=5;
      while(true){
        if(n<start) break;
        ans+=(n/start);
        start*=5;
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

 
#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
#define lil long long int
 
     //write your code
  bool solve(){
      lil a,b;
      cin>>a>>b;
      lil diff=abs(a-b);
      b=min(a,b)-diff;
      a=b;
      if(a<0)return 0;
      if(a%3==0) return 1;
      return 0;
 }
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
   lil t;
   cin>>t;
    while(t--){
      if(solve()){
        cout<<"YES"<<endl;
      }
      else{
        cout<<"NO"<<endl;
      }
    }
    
}
 
 
//HARE KRISHNA HARE KRISHNA
//KRISHNA KRISHNA HARE HARE
//HARE RAMA HARE RAMA
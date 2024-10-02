

 
 
#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
#define lil long long int
 
     //write your code
  void solve(){
    
      lil n;
      cin>>n;
      lil sum=(1+n)*(n)/2;
      if(sum%2==1){
        cout<<"NO";
        return;
      }
      cout<<"YES"<<endl;
      lil new_sum=sum/2;
      unordered_set <lil> elements;
      lil x=n;
      while(new_sum){
        if(new_sum>=x) {
            new_sum-=x;
            elements.insert(x);
        }
        x--;
      }
      lil first=elements.size();
      cout<<first<<endl;
      for(auto it:elements){
        cout<<it<<" ";
      }
      cout<<endl<<n-first<<endl;
      for(lil i=1;i<=n;i++){
        if(elements.find(i)==elements.end()) cout<<i<<" ";
      }
     
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
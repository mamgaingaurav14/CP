
 
#include <bits/stdc++.h>
using namespace std;
#define lil long long int
 
     //write your code
  void solve(){
    
       lil n;
      cin>>n;
      for(lil k=1;k<=n;k++){
         //
         lil total=(k*k)*((k*k)-1)/2;
         lil remove=4*(k-2)*(k-1);
        cout<<total-remove<<endl;
      }
 
 
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


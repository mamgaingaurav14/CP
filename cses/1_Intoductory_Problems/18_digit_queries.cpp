
 
#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
#define lil long long int
 //at first the wuestion was looking impossible 
 //but it was indeed possible 
 
     //write your code
  lil solve(){
    
      lil n;
      cin>>n;
      if(n<=9) return n;
      lil i=1,j=1,final=0;
      lil initial=0;
      while(true){
        lil prod=i*j*9;
        final+=prod;
        if(final>=n){
          initial=final-prod;
          break;
        }
        i*=10;j++;
      }
      lil position=initial+1;
      lil extra=n-position;
      lil no_to_pass=extra/j;
      lil number=i+no_to_pass;
      lil index=extra%j;
      
      lil x=j-1;
      while(number){
         lil bit=(number%10);
         if(x==index){
          return bit;
         }
         number/=10;
         x--;
      }
   return -1;
 }
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
   int t;
   cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    
}
 
 
//HARE KRISHNA HARE KRISHNA
//KRISHNA KRISHNA HARE HARE
//HARE RAMA HARE RAMA
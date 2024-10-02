
 
#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
#define lil long long int
 
     //write your code
     void recursion(vector<lil> &apples,lil index,lil current,lil &sum,lil &mini){
        //take or not take 
        //if(take)
        if(mini==!(sum%2)){
            return;
        }
        lil n=apples.size();
        if(index==n) return;
        lil diff=abs(sum-2*current);

        mini=min(diff,mini);

       //take
       recursion(apples,index+1,current,sum,mini);
       current+=apples[index];
       recursion(apples,index+1,current,sum,mini);
     }
  lil solve(){
    
       lil n;
      cin>>n;
      lil sum=0;
      vector<lil> apples(n,0);
     int i=0;
      while(n--){
        cin>>apples[i];
         sum+=apples[i];
         i++;
      }
      lil mini=INT_MAX;
      recursion(apples,0,0,sum,mini);
      return mini;
 }
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
  cout<<solve();
    
}
 
 
//HARE KRISHNA HARE KRISHNA
//KRISHNA KRISHNA HARE HARE
//HARE RAMA HARE RAMA
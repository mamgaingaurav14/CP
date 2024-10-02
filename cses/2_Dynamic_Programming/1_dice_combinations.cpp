
 
#include <bits/stdc++.h>
using namespace std;
#define lil long long int
const lil MOD=1e9+7;
//Approach 
//we will use a slinding window sum approach 
//t(n)=o(n) and space complexity o(1);
     //write your code
  lil solve(lil n){
    if(n<=1) return n;
    queue <lil> dp;
    lil i=2,sum=1,val=1;
    dp.push(val);
    for(;i<=6;i++){
        val=sum+1;
        sum+=val;
        dp.push(val);
        if(i==n) return val;
    }
    for(lil i=7;i<=n;i++){
       val=sum;
       sum = (2*val-dp.front()+MOD)%MOD;
       dp.pop();
       dp.push(val);
    }
    return val%MOD;
 }
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
   lil t;
   cin>>t;
   cout<<solve(t)<<endl;
}
 
 
//HARE KRISHNA HARE KRISHNA
//KRISHNA KRISHNA HARE HARE
//HARE RAMA HARE RAMA


/*

//recursive function in first go
 lil solve_rec(lil n){
    if(n==0) return 1;
    if(n==1) return 1;
    lil i=1;
    lil ans=0;
    while(n>=i && i<=6){
        ans+=solve_rec(n-i);
        i++;
    }
    return ans;
    //write your code
 }
 */
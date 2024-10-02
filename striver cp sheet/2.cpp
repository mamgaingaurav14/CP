//https://codeforces.com/problemset/problem/282/A
#include <bits/stdc++.h>
using namespace std;
#define lil long long int
const int MOD=1e9+7;
 #define pb push_back
 #define sort(vec) sort(vec.begin(),vec.end())
 #define yes cout<<"YES"<<'\n';
 #define no cout<<"NO"<<'\n';
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
   
       //solve;
       lil n;
       cin>>n;
        lil ans=0;
        lil power=1;
       while(n){
        lil digit=n%10;
        if(n/10==0 && digit==9){
          //last bit 
           ans+=power*9;
        }
        else if(digit>4 ){
            ans+=power*(9-digit);
        }
        else{
            ans+=power*(digit);
        }
        n/=10;
        
        power*=10;
       }

       cout<<ans;
       return 0;
    
}
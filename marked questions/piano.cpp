//https://www.codechef.com/problems/PIANO1?tab=statement
//understood using solution
#include <bits/stdc++.h>
using namespace std;
#define lil long long int
const int MOD=1e9+7;
 #define pb push_back
 #define sort(vec) sort(vec.begin(),vec.end())
 #define yes cout<<"yes"<<'\n';
 #define no cout<<"no"<<'\n';
 #define bob cout<<"bob"<<'\n';
 #define alice cout<<"alice"<<'\n';
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
       //solve;
       string s;
       cin>>s;
       int n;
       cin>>n;
       int step_size=0;
       for(char c:s){
           if(c=='T') step_size+=2;
           if(c=='S') step_size+=1;
       }
       int ans=0;
       int pattern_size=step_size;
       while(pattern_size<12*n){
           ans+=12*n-pattern_size;
           pattern_size+=step_size;
       }
       cout<<ans<<"\n";
    }
}
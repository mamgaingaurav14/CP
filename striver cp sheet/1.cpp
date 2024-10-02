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
       int n;
       cin>>n;
       int cnt=0;
       while(n--){
        string a;
        cin>>a;
        for(char c:a){
          if(c=='+'){
            cnt++;
            break;
          }
          if(c=='-'){
            cnt--;
            break;
          }
        }
       }
       cout<<cnt;
       return 0;
    
}
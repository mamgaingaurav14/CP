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
    lil n;
    cin>>n;
    lil a;
    lil prev=INT_MIN;
    lil cnt=0;
    while(n--){
      cin>>a;
      if(a<prev){
        cnt+=(prev-a);
        a=prev;
      }
      prev=a;
    }
    cout<<cnt;
}
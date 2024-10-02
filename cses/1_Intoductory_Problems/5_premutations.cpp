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
  
    if(n<4 & n!=1){
        cout<<"NO SOLUTION";
    }
    else{
    lil odd=1;
    lil even=2;
    while(even<=n){
        cout<<even<<" ";
        even+=2;
    }
    while(odd<=n){
        cout<<odd<<" ";
        odd+=2;
    }
    return 0;
     
    }
 
}
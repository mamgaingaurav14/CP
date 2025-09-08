//HARE KRISHNA HARE KRISHNA
//KRISHNA KRISHNA HARE HARE
//HARE RAMA HARE RAMA
//RAMA RAMA HARE HARE

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
gp_hash_table<int, int> table;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};
gp_hash_table<key, int, chash> table;

void print_vec(vector<int> &values){
     for(int i:values) cout<<i<<" ";
     cout<<endl;

}
void print_vec(vector<vector<int>> &values){
     for(auto i:values){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
     }
}
long long mod_pow(long long base, long long exp) {
    long long result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}


if(solve()){
            cout<<"YES"<<endl;
        }
        else{
             cout<<"NO"<<endl;
        }

#include <bits/stdc++.h>
using namespace std;
#define lil long long int
const int MOD=1e9+7;
const double PI=3.141592653589793238462;
lil gcd(lil a, lil b) { return b == 0 ? a : gcd(b, a % b); }  // __gcd
lil lcm(lil a, lil b) { return ((a * b) / gcd(a, b)); }

 void solve(){
    
      int n;
      cin>>n;
       vector<int> arr(n,0);
       for(int i=0;i<n;i++){
           cin>>arr[i];
       }
     
     //write your code


 }
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
   int t;
   cin>>t;
    while(t--){
        solve();
    }
    
}

//Jai Hind
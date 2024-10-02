//https://cses.fi/problemset/task/1068
#include <bits/stdc++.h>
using namespace std;
#define lil long long int
const int MOD = 1e9 + 7;
 #define yes cout<<"yes"<<'\n';
 #define no cout<<"no"<<'\n';
 
//my own code
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lil n;
    cin >> n;
    while (n!=1) {
      cout<<n<<" ";
      if(n&1){
        n=n*3+1;
      }
      else{
        n/=2;
      }
    }
    cout<<1<<" ";
}
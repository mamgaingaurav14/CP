//https://codeforces.com/problemset/problem/1903/A
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
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n>>k;
        int a;
        bool flag=true;
        int prev=INT_MIN;
        for (int i = 0; i < n; i++) {
            cin >> a;
            if(a<prev) flag=false;
            prev=a;
        }
        if(k<2 && flag==false) {
        no;
        }
        else{
          yes;
        } 
}
}

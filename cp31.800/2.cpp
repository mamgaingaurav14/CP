//https://codeforces.com/problemset/problem/1901/A
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
        int n,x;
        cin >> n>>x;
        int cnt=INT_MIN;
        int a;
        int prev=0;
        while (n--) {
            cin >> a;
            int diff=a-prev;
            cnt=max(diff,cnt);
            prev=a;
        }
        int diff=2*(x-prev);
        cnt=max(diff,cnt);
        cout<<cnt<<endl;
}
}

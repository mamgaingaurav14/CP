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
        int n;
        cin >> n;
        char c;
        int cnt=0;
        int total=0;
        bool flag=false;
        while(n--){
            cin>>c;
            if(c=='.'){
                cnt++;
                if(cnt==3) flag=true;
                total++;
            }
            else{
                cnt=0;
            }
        }
        if(flag) total=2;
        cout<<total<<endl;
     }
return 0;
}

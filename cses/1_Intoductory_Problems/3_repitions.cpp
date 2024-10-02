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
    string s;
    cin>>s;
    lil cnt=1;
    char prev='#';
    lil maxi=INT_MIN;
    for(char c:s){
       if(prev==c){
        cnt++;
       }
       else{
        maxi=max(maxi,cnt);
        cnt=1;
        prev=c;
       }
    }
    maxi=max(maxi,cnt);
    cout<<maxi;
}
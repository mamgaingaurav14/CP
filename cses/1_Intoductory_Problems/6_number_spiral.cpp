#include <bits/stdc++.h>
using namespace std;
#define lil long long int
const int MOD=1e9+7;
 #define pb push_back
 #define sort(vec) sort(vec.begin(),vec.end())
 #define yes cout<<"YES"<<'\n';
 #define no cout<<"NO"<<'\n';

 lil solve2(lil y,lil x){
    if(x&1){
       if(y<=x) return x*x-y+1;
    }
    else{
        if(y<=x) return ((x-1)*(x-1))+y;
    }
    if(y&1){
        if(x<=y) return ((y-1)*(y-1))+x;
    }
    else{
        if(x<=y) return y*y-x+1;
    }
    return -1;
 }
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    
    while(t--){
        lil y,x;
        cin>>y>>x;
        cout<<solve2(y,x)<<endl;
    }
}

    

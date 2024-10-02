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
    int t;
    cin>>t;
    while(t--){
       //solve;
       int n,k;
       cin>>n>>k;
       string s;
       cin>>s;
       
       vector<int> front_zero(n,0);
       vector<int> back_one(n,0);
       int cnt=0;
       for(int i=0;i<n;i++){
          back_one[i]=(cnt);
          if(s[i]=='1'){
            cnt++;
          }
       }
       cnt=0;
       for(int i=n-1;i>=0;i--){
          front_zero[i]=(cnt);
          if(s[i]=='0'){
            cnt++;
          }
       }
       int index_i=0;
       int index_j=n-1;
       bool flag=true;
       while(k-- && index_i<index_j && flag){
           while(index_i<n && s[index_i]!='1'){
               index_i++;
           }
           while(index_j>=0  && s[index_j]!='0'){
               index_j--;
           }
           if(index_i>=n || index_j<0 ) {
               flag=false;
               break;
           }
           int a=front_zero[index_i];
           int b=back_one[index_j];
           if(a>b){
               s[index_i]='0';
               index_i++;
               
           }
           else{
              s[index_j]='1';
              index_j--;
           }
       }
       cnt=0;
       int ans=0;
       for(int i=0;i<n;i++){
          if(s[i]=='1') cnt++;
          if(s[i]=='0'){
              ans+=cnt;
          }
       }
       cout<<ans<<endl;
    }
    
}
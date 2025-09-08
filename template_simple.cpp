
 
#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
#define lil long long int

const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};
 void print_vec(vector<int> &values){
      for(auto i:values) cout<<i<<" ";
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

     //write your code
  lil solve(){
    
      lil n,k;
      cin>>n>>k;
       vector<lil> arr(n,0);
       for(lil i=0;i<n;i++){
           cin>>arr[i];
       }
       return 1;
     //write your code



 }
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
   lil t;
   cin>>t;
    while(t--){
    cout<<solve()<<endl;
     
     if(solve()){
            cout<<"YES"<<endl;
        }
        else{
             cout<<"NO"<<endl;
        }


    }
    
}
 
 
//Jai Hind

 
#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
#define lil long long int

const int N=8;
vector<int> col(N,0);
vector<int> diag1(2*N-1,0);
vector<int> diag2(2*N-1,0);
 vector<vector<int>> blocked(N,vector<int> (N,0));
     //write your code
int ans=0;
  void solve(int x){
     if(x==8){
      ans++;
      return;
     }
     for(int y=0;y<N;y++){
      if(col[y] || diag1[x+y] || diag2[x-y+N-1] || blocked[x][y]) continue;
      col[y]=1 ; diag1[x+y]=1 ; diag2[x-y+N-1]=1;
      solve(x+1);
      col[y]=0 ; diag1[x+y]=0 ; diag2[x-y+N-1]=0;
     }
  }
  void start(){
    char c;   
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        cin>>c;
        if(c=='*') blocked[i][j]=1;
      }
    }
    solve(0);
 }
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
   start();
   cout<<ans;
}
 
 
//HARE KRISHNA HARE KRISHNA
//KRISHNA KRISHNA HARE HARE
//HARE RAMA HARE RAMA
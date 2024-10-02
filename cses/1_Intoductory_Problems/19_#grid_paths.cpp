//my answer which is partially correct and exceeding time limits 
#include <bits/stdc++.h>
using namespace std;
 
const int n=7;
int ans=0;
string given;
vector<vector<int>> visited(n,vector<int> (n,0));
  bool check(int x,int y){
    return (x>=0 && y>=0 && x<n && y<n && visited[x][y]==0 );
  }
  void dfs(int x,int y,int index){
   if((index==n*n-1) || (x==n-1 && y==0)){
    if((index==n*n-1) && (x==n-1 && y==0)) ans++;
    return;
   }
   
   //
   if(x-6+y>48-index) return ;
   if(!check(x+1,y) && !check (x-1,y)){
    if(check(x,y+1) && check (x,y-1)){
      return;
    }
    if(!check(x,y+1) && !check (x,y-1)){
    if(check(x+1,y) && check (x-1,y)){
      return;
    }
   }
   }
 
   visited[x][y]=1;
   char c=given[index];
   if(c=='R'|| c=='?' ){
    if(check(x,y+1)) dfs(x,y+1,index+1);
   }
   if(c=='D'|| c=='?' ){
    if(check(x+1,y)) dfs(x+1,y,index+1);
   }
   if(c=='L'|| c=='?' ){
    if(check(x,y-1)) dfs(x,y-1,index+1);
   }
   if(c=='U'|| c=='?' ){
    if(check(x-1,y)) dfs(x-1,y,index+1);
   }
   visited[x][y]=0;
  }
int main(){
   ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
   cin>>given;
   dfs(0,0,0);
   cout<<ans;
 
}
 
 
//HARE KRISHNA HARE KRISHNA
//KRISHNA KRISHNA HARE HARE
//HARE RAMA HARE RAMA


//the correct official from jonathan 
#include <bits/stdc++.h>
 
using namespace std;
const int N = 7;
 
int ans;
char c[N*N+1];
bool vis[N+1][N+1];
 
bool inbounds(int x, int y){
    return 1 <= x && x <= N && 1 <= y && y <= N;
}
 
void dfs(int x, int y, int i){
    if(i == N*N-1 || (x == N && y == 1)){
        ans += (i == N*N-1 && (x == N && y == 1));
        return;
    }
 
    if((!inbounds(x+1, y) || vis[x+1][y]) && (!inbounds(x-1, y) || vis[x-1][y]))
        if(inbounds(x, y-1) && !vis[x][y-1] && inbounds(x, y+1) && !vis[x][y+1])
            return;
    if((!inbounds(x, y+1) || vis[x][y+1]) && (!inbounds(x, y-1) || vis[x][y-1]))
        if(inbounds(x+1, y) && !vis[x+1][y] && inbounds(x-1, y) && !vis[x-1][y])
            return;
 
    vis[x][y] = true;
    if(c[i] == 'D' || c[i] == '?')
        if(inbounds(x+1, y) && !vis[x+1][y])
            dfs(x+1, y, i+1);
    if(c[i] == 'U' || c[i] == '?')
        if(inbounds(x-1, y) && !vis[x-1][y])
            dfs(x-1, y, i+1);
    if(c[i] == 'R' || c[i] == '?')
        if(inbounds(x, y+1) && !vis[x][y+1])
            dfs(x, y+1, i+1);
    if(c[i] == 'L' || c[i] == '?')
        if(inbounds(x, y-1) && !vis[x][y-1])
            dfs(x, y-1, i+1);
    vis[x][y] = false;
}
 
int main(){
    scanf(" %s", c);
    dfs(1, 1, 0);
    printf("%d\n", ans);
}

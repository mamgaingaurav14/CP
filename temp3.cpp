#include <bits/stdc++.h>
using namespace std;
 

vector<int> parent,sz;

 void UnionbySize(int u,int v){
     int pu=findParent(u),pv=findParent(v);
     if(pu>pv) parent[pv]=pu;
     else parent[pu]=pv;
 }
 void UnionbySize(int u,int v){
     int pu=findParent(u),pv=findParent(v);
     if(pu>pv) parent[pv]=pu;
     else parent[pu]=pv;
 }


 int findParent(int a){
    if(parent[a]==a) return a;
    return findParent(parent[a]);
 }
   int spanningTree(int n, vector<vector<int>>& edges) {

        parent.resize(n);sz.resize(n);
        for(int i=0;i<n;i++) { parent[i]=i;sz[i]=1;} 


        sort(edges.begin(),edges.end(),[&](vector<int> &a,vector<int> &b){
            return a[2]<b[2];
        });
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:edges){
            int u=it[0],v=it[1],w=it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        int ans=0,cnt=0;
        for(auto it:edges){
           int u=it[0],v=it[1],w=it[2];
           if(findParent(u)==findParent(v)) continue;
           cnt++;ans+=w;
           UnionbySize(u,v);
           if(cnt==n-1) return ans;
        }
        return -1;
        
    }




int main(){
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
vector<vector<int>> points={{6,2},{4,4},{2,6}};
cout<<numberOfPairs(points)<<endl;

}
   
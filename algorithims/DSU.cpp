 class DSU{
      vector <int> parent,rank,size;
      public:
       DSU(int n){//constructor
        parent.resize(n+1);rank.resize(n+1,0);size.resize(n+1,1);
        for(int i=0;i<=n;i++) parent[i]=i;//itself a parent;
       }
       int findParent(int x){
        if(parent[x]==x) return x;
        return parent[x]=findParent(parent[x]);//finding the parent 
       }
       void Union_by_Rank(int u,int v){
          int pu=findParent(v),pv=findParent(u);
          if(pu==pv) return;
          if(rank[pu]>rank[pv]) parent[pv]=pu;
          else if(rank[pu]<rank[pv]) parent[pu]=pv;
          else{
            rank[pu]++;
            parent[pv]=pu;
          }
            //then connect v to u lower to higher 
            //connect them
       }
       void Union_by_Size(int u,int v){
          int pu= findParent(v),pv=findParent(u);
          if(pu==pv) return;
          if(size[pu]>size[pv]) {//connect to pu
            parent[pv]=pu;size[pu]+=size[pv];
          }
          else {
            parent[pu]=pv;size[pv]+=size[pu];
          }
           //then connect v to u lower to higher 
            //connect them
       }
 };
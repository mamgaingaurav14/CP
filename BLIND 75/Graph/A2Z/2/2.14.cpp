class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& arr) {
       vector<int> ans;
       int n=arr.size();
       if(n==0) return ans;
       node* head= new node(arr[0][1]);
       node* temp=new node(arr[0][0]);
       head->next=temp;

       for(int i=1;i<n;i++){
         int first=arr[i][1];
         int second=arr[i][2];
         
       }
    }
};


//gfg directed me cycle cycle 
 bool dfs(int i, vector<int> adj[], vector<int> &vis, vector<int> &path_vis) {
    vis[i] = 1;
    path_vis[i] = 1;
    
    for (int j : adj[i]) {
        if (vis[j] == 0) { // If node j is not visited
            if (dfs(j, adj, vis, path_vis)) return true;
        } else if (path_vis[j] == 1) { // If node j is visited and is in the current path
            return true;
        }
    }
    
    path_vis[i] = 0; // Backtrack: Remove the node from the current path
    return false;
}

// Function to detect cycle in a directed graph.
bool isCyclic(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    vector<int> path_vis(V, 0);
    
    for (int i = 0; i < V; i++) {
        if (vis[i] == 0) { // Start DFS if node i is not visited
            if (dfs(i, adj, vis, path_vis)) return true;
        }
    }
    
    return false;
}


    //uisng simple logic of path visited 
//
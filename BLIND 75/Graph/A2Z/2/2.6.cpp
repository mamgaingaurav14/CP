//542 question 0-1 matrix 
#include <bits/stdc++.h>
using namespace std;



//why this solution is nto working since 
//here the recutison stack is overflowing 
//since we re visitig the same nodes 
//again and again and casuing an infinite loop;
class Solution {
public:
    int find(int i,int j,vector<vector<int>>& mat,vector<vector<int>> &answer){
        int m=mat.size();
        int n=mat[0].size();
        if(mat[i][j]==0) return answer[i][j]=0;
        if(answer[i][j]!=-1) return answer[i][j];
        int a=INT_MAX,b=INT_MAX,c=INT_MAX,d=INT_MAX;
        if(i-1>=0) a=1+find(i-1,j,mat,answer);
        if(j-1>=0) b=1+find(i,j-1,mat,answer);
        if(i+1<m) c=1+find(i+1,j,mat,answer);
        if(j+1<n) d=1+find(i,j+1,mat,answer);
        return answer[i][j]=min(min(a,b),min(c,d));
    }   
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> answer(m,vector<int> (n,-1));
        for(int i=0;i<m;i++){
            for( int j=0;j<n;j++){
                if(answer[i][j]!=-1) continue;
                answer[i][j]=find(i,j,mat,answer);
            }
        }
        return answer;
    }
};


//here we will use bfs approach to 
//get the answer its a question just like 
//rotten tomatoes wuestion 


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
         int m=mat.size();
        int n=mat[0].size();
        queue<vector<int>> q;
         vector<vector<int>> visited(m,vector<int>(n,0));
        vector<vector<int>> answer(m,vector<int>(n,-1));
         for(int i=0;i<m;i++){
            for( int j=0;j<n;j++){
                if(mat[i][j]==1) continue;
                visited[i][j]=1;
                q.push({i,j,0});
            }
        }
        while(!q.empty()){
            int i=q.front()[0];
            int j=q.front()[1];
            int dist=q.front()[2];
            answer[i][j]=dist;
            q.pop();
            if(i-1>=0 && visited[i-1][j]==0) {
                 visited[i-1][j]=1;
                q.push({i-1,j,dist+1});
            }
            if(j-1>=0 && visited[i][j-1]==0){
             q.push({i,j-1,dist+1});
             visited[i][j-1]=1;
            } 
            if(i+1<m && visited[i+1][j]==0 ){
                q.push({i+1,j,dist+1});
                visited[i+1][j]=1;
            }
            if(j+1<n && visited[i][j+1]==0) {
                q.push({i,j+1,dist+1});
                visited[i][j+1]=1;
            }
        }
        return answer;
    }
};
int main(){
    return 0;
}
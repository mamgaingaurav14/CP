#include <bits/stdc++.h>
using namespace std;


//not going to work since its a graph approach problem 
//for shortest path dijkstra

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long int ans=0;
        int n=cost.size();
        vector<pair<char,char>> vec;
        unordered_map <int,int> hash;
        for(int i=0;i<n;i++){
          vec.push_back({original[i],changed[i]});
          hash[cost[i]]=i;
        }
        
        sort(cost.begin(),cost.end());
        for(int i=0;i<source.size();i++){
          if(source[i]!=target[i]){
            bool flag=true;
            for(int j=0;j<n;j++){
                if(vec[hash[cost[j]]]==pair <char,char> ({source[i],target[i]})){
                   flag=false;
                   ans+=cost[j];
                   break;
                }
            }
            if(flag) return -1;
            
          }
        }
        return ans;
    }
};
//this is the solution fro this

class Solution {
public:
    vector<vector<long long>> floydWarshall(vector<vector<pair<int, long long>>>& adjList) {
        int numVertices = 26;
        vector<vector<long long>> dist(numVertices, vector<long long>(numVertices, LLONG_MAX));
        
        for (int i = 0; i < numVertices; i++) {
            for (const auto& neighbor : adjList[i]) {
                dist[i][neighbor.first] = min(dist[i][neighbor.first], neighbor.second);
            }
        }
        
        for (int k = 0; k < numVertices; k++) {
            for (int i = 0; i < numVertices; i++) {
                for (int j = 0; j < numVertices; j++) {
                    if (dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        
        return dist;
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int numVertices = 26;
        vector<vector<pair<int, long long>>> adjList(numVertices);
        
        for (int i = 0; i < cost.size(); i++) {
            int from = original[i] - 'a';
            int to = changed[i] - 'a';
            long long transformationCost = cost[i];
            adjList[from].push_back({to, transformationCost});
        }
        
        vector<vector<long long>> dist = floydWarshall(adjList);
        long long totalCost = 0;
        
        for (int i = 0; i < source.size(); i++) {
            int sourceChar = source[i] - 'a';
            int targetChar = target[i] - 'a';
            if (source[i] != target[i]) {
                if (dist[sourceChar][targetChar] == LLONG_MAX) return -1;
                totalCost += dist[sourceChar][targetChar];
            }
        }
        
        return totalCost;
    }
};
int main(){
    return 0;
}
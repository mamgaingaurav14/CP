#include <bits/stdc++.h>
using namespace std;
#define lil long long int
const int MOD=1e9+7;
 #define pb push_back
 #define sort(vec) sort(vec.begin(),vec.end())
 #define yes cout<<"YES"<<'\n';
 #define no cout<<"NO"<<'\n';
 #define bob cout<<"bob"<<'\n';
 #define alice cout<<"alice"<<'\n';

 //backtracking solution 
 //we learned that always revert back any changes you make to oroginal array ;
bool solve(vector<vector<char>>& matrix,int i,int j, string &word,int index){
        if(index==int(word.size())) return true;
        int m=matrix.size();
        int n=matrix[0].size();
        if(i<0 || i>=m || j<0 || j>=n) return false;
        if(matrix[i][j]==word[index]){
           matrix[i][j]='#';
           if( solve(matrix,i,j+1,word,index+1) || solve(matrix,i,j-1,word,index+1) || solve(matrix,i+1,j,word,index+1) ||  solve(matrix,i-1,j,word,index+1)) return true;
           matrix[i][j]=word[index];
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(solve(board,i,j,word,0)) {
                    cout<<i<<" "<<j<<" ";
                    return true;
                }
            }
        }
        return false;
    }
    int main(){
        return 0;
    }
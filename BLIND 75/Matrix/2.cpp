 #include <bits/stdc++.h>
using namespace std;
 class Solution {
public:
    vector<int> ans;
    void solve(vector<vector<int>>& matrix,int start_row,int end_row,int start_col,int end_col){
       if(start_row>end_row || start_col>end_col) return ;
       int i=start_row;
       int j=start_col;
       while(j!=end_col) {
        ans.push_back(matrix[i][j]);
        j++;
       }
       while(i!=end_row){
        ans.push_back(matrix[i][j]);
        i++;
       }
       while(j!=start_col){
         ans.push_back(matrix[i][j]);
        j--;
       }
       while(i!=start_row){
         ans.push_back(matrix[i][j]);
        i--;
       }
      solve(matrix,start_row+1,end_row-1,start_col+1,end_col-1);
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        solve(matrix,0,m-1,0,n-1);
        return ans;
    }
 
};


//bad code but m not intrested in writig  anew code 
class Solution {
public:
    vector<int> ans;
    void solve(vector<vector<int>>& matrix,int start_row,int end_row,int start_col,int end_col){
       if(start_row>end_row || start_col>end_col) return ;
       int i=start_row;
       int j=start_col;
       while(true) {
        ans.push_back(matrix[i][j]);
        if(j==end_col) break;
        j++;
       }
       if(i==end_row) return;
       i++;
       while(true){
        ans.push_back(matrix[i][j]);
        if(i==end_row) break;
        i++;
       }
       j--;
       if(j<start_col) return;
       while(true){
         ans.push_back(matrix[i][j]);
         if(j==start_col) break;
         j--;
       }
       i--;
       if(i<start_row) return;
       while(true){
         if(i==start_row) break;
         ans.push_back(matrix[i][j]);
        i--;
       }
      solve(matrix,start_row+1,end_row-1,start_col+1,end_col-1);
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        solve(matrix,0,m-1,0,n-1);
        return ans;
    }
 
};
int main(){
    return 0;
}
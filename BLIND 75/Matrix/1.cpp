class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rows;
        unordered_set<int> cols;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
         for(int j=0;j<n;j++){
            if(matrix[i][j]==0){
                rows.insert(i);
                cols.insert(j);
            }
          }
        }
        for(int i:rows){
            matrix[i]=vector<int> (n,0);
        }
        for(int j:cols){
              for(int i=0;i<m;i++){
                matrix[i][j]=0;
              }
        }
    }
};
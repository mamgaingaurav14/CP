class Solution {
public:

   //brute force apporach 
    void rotate(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> answer(m,vector<int> (n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                answer[j][n-1-i]=matrix[i][j];
            }
        }
        matrix=answer;
    }

    //optimal approach 
    //transpos the matrix  then reverese it 
     void rotate(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        //transpore
        for(int i=0;i<m;i++){
            for(int j=0;j<i;j++){
              swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<m;i++){
            int start=0;
            int end=n-1;
           while(start<end){
              swap(matrix[i][start++],matrix[i][end--]);
            }
        }
    }
};
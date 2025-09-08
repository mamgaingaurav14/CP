  #include <bits/stdc++.h>
using namespace std;
#define lil long long int
const int MOD=1e9+7;
 #define pb push_back

 //approach 1 using normal technique 
 vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> min_elements;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            min_elements.push_back(*min_element(matrix[i].begin(),matrix[i].end()));
        }
        vector<int> answer;
        for(int i=0;i<n;i++){
            pair<int,int> maxi={INT_MIN,INT_MIN};
            for(int j=0;j<m;j++){
                maxi=max(maxi,{matrix[j][i],j});
            }
            if(min_elements[maxi.second]==maxi.first){
               answer.push_back(maxi.first);
            }
        }
        return answer;
    }

    //approach 2 undersatding the observation 
//there can be at most one lucky no in the matrix
  vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int N = matrix.size(), M = matrix[0].size();
        
        int rMinMax = INT_MIN;
        for (int i = 0; i < N; i++) {

            int rMin = INT_MAX;
            for (int j = 0; j < M; j++) {
                rMin = min(rMin, matrix[i][j]);
            }
            rMinMax = max(rMinMax, rMin);
        }
        
        int cMaxMin = INT_MAX;
        for (int i = 0; i < M; i++) {

            int cMax = INT_MIN;
            for (int j = 0; j < N; j++) {
                cMax = max(cMax, matrix[j][i]);
            }
            cMaxMin = min(cMaxMin, cMax);
        }
        
        if (rMinMax == cMaxMin) {
            return {rMinMax};
        }
        
        return {};
    }
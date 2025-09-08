//approach is  simple 
//but it is a question worth revisoing for sure 
//uncerstadning the qurstiom 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int m, int n, int i, int j) {
        vector<vector<int>> directions={{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<int>> ans={{i,j}};
        int d=0;
        int steps=0;
        while(ans.size()<(m*n)){
           if(d==0 || d==2) steps++;
           for(int x=0;x<steps;x++){
            i+=directions[d][0];
            j+=directions[d][1];
            if(i>=0 && j>=0 && i<m && j<n) ans.push_back({i,j});
            if(ans.size()==(m*n)) return ans;
           }
           d=(d+1)%4;
        }
        return ans;

    }
};
int main(){
    return 0;
}
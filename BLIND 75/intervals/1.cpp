
 
#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
#define lil long long int
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        lil n=skill.size();
        lil s=0;
        for(lil i:skill) s+=i;
        if(s%(n/2)) return -1;
        lil ps=s/(n/2);
        sort(skill.begin(),skill.end());
        lil ans=0;
        for(lil i=0;i<n-1;i++){
          auto it =lower_bound(skill.begin()+i+1,skill.end(),(ps-skill[i]));
          if(it==skill.end()) return -1;
          lil index=it-skill.begin();
          ans+=(skill[i]*skill[index]);
          skill[index]=-1;
        }
        return ans;
    }
};
    void print(vector<vector<int>> x){
        int n=x.size();
        int m=x[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<x[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    
}
 
 
//HARE KRISHNA HARE KRISHNA
//KRISHNA KRISHNA HARE HARE
//HARE RAMA HARE RAMA
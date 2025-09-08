  #include <bits/stdc++.h>
using namespace std;
#define lil long long int


///intervals
class Solution {
public:
 vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        for(int i=0;i<m;i++){
            pair<int,int> target={queries[i][0],queries[i][1]};
            auto jt= lower_bound(valid.begin(), valid.end(), target);
            if(jt!=valid.end()){
                //found
                //cout<<jt->first<<" "<<jt->second<<endl;
          if((queries[i][0]<jt->first && queries[i][1]>=jt->first) ||( queries[i][0]>=jt->first && queries[i][1]>jt->second) ) ans[i]=0;
            }
            else{
                //cout<<"not found"<<endl;
                 pair<int,int> lx=valid.back();
                if((queries[i][1]>lx.second)) ans[i]=false;
                //not found
            }
        }
        return ans;
   
    }
};
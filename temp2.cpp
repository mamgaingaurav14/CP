
 
#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
#define lil long long int

vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while(k--){
            lil mini=0;
            for(lil i=1;i<nums.size();i++){
               if(nums[i]<nums[mini]) mini=i;
            }
            nums[mini]=(nums[mini]%MOD*multiplier%MOD)%MOD;
        }
        for(lil i=0;i<nums.size();i++){
            nums[i]=nums[i]%MOD;
        }
        return nums;
    }
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
   
    
}
 
 
//HARE KRISHNA HARE KRISHNA
//KRISHNA KRISHNA HARE HARE
//HARE RAMA HARE RAMA
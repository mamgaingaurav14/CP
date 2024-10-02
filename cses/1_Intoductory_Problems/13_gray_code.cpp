
 
#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
#define lil long long int
 
 //we used muliplyinf the string into twice every time 
 
     //write your code
  void solve(){
     lil n;
     cin>>n;
     vector<string> answer={""};
     for(int i=1;i<=n;i++){
        vector<string> new_answer;
        for(auto it:answer){
            it="0"+it;
            new_answer.push_back(it);
        }
        reverse(answer.begin(),answer.end());
        for(auto gt:answer){
            gt="1"+gt;
            new_answer.push_back(gt);
        }
        answer=new_answer;
     }
     for(auto it:answer){
        cout<<it<<endl;
     }
      
     

 }
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    
}
 
 
//HARE KRISHNA HARE KRISHNA
//KRISHNA KRISHNA HARE HARE
//HARE RAMA HARE RAMA
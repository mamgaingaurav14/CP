
 
#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
#define lil long long int
 
     //write your code
  string solve(){
     string given;
     cin>>given;
     unordered_map <char,int> hash;
     lil sz=given.size();
     int i=sz%2;
     for(char c:given){
        hash[c]++;
     }
     string answer="";
     string def="NO SOLUTION";
     char odd='#';
     int j=0;
     for(auto it:hash){
       if(it.second%2==1){
        //oddd count of character
        odd=it.first;
        j++;
        if(j>i) return def;
       }
       else{
        //even characters
        int no=it.second/2;
        while(no--){
        answer.push_back(it.first);
        }
       }
     }

     string rev(answer.rbegin(),answer.rend());
     string middle="";
     while(hash[odd]--){
        middle.push_back(odd);
     }
     answer=answer+middle+rev;
     return answer;
 }
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout<<solve();
    
}
 
 
//HARE KRISHNA HARE KRISHNA
//KRISHNA KRISHNA HARE HARE
//HARE RAMA HARE RAMA
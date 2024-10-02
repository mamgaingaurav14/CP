
 
#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
#define lil long long int

//the catch is in printing the probelms 

/*
  void print(map<char,lil> &hash,int size){
    //traverse in the map 
    if(size==0) {
        cout<<"\n";
        return;
    }
    for(auto &it:hash){
      int freq=it.second;
      if(freq<1) continue;
      hash[it.first]--;
      cout<<it.first;
      print(hash,size-1);
      hash[it.first]++;
    }
  }
*/
   void print(map<char,lil> &hash,string &current,lil n){
    //traverse in the map 
    lil string_size=current.size();
    if(string_size==n) {
        cout<<current<<endl;
        return;
    }
    for(auto &it:hash){
      int freq=it.second;
      if(freq<1) continue;
      hash[it.first]--;
      current.push_back(it.first);
      print(hash,current,n);
      hash[it.first]++;
      current.pop_back();
    }
  }
 
  void solve(){
    string given;
    cin>>given;

    //factorials for no
    lil num=given.size();
    vector<lil> fact(num+1,1);
    for(int i=2;i<=num;i++){
        fact[i]=i*fact[i-1];
    }
    map <char,lil> hash;
    for(char c:given){
        hash[c]++;
    }
    lil den=1;
    for(auto it:hash){
        den*=fact[it.second];
    }
    lil count=(fact[num])/(den);
    cout<<count<<endl;
    

    lil n=num;
    string current="";
    print( hash,current,n);
   //now finding the combinations

 }
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
   solve();
    
}
 
 
//HARE KRISHNA HARE KRISHNA
//KRISHNA KRISHNA HARE HARE
//HARE RAMA HARE RAMA
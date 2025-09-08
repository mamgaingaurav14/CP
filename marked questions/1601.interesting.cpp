//https://www.codechef.com/problems/PROBLEMS
#include <bits/stdc++.h>
using namespace std;
#define lil long long int
const int MOD=1e9+7;
 #define pb push_back
 #define sort(vec) sort(vec.begin(),vec.end())
 #define yes cout<<"yes"<<'\n';
 #define no cout<<"no"<<'\n';
 #define bob cout<<"bob"<<'\n';
 #define alice cout<<"alice"<<'\n';
 void rev(bool &flag){
     if(flag) flag=false;
     else flag=true;
 }
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
       //solve;
       int P,S;
       cin>>P>>S;
       vector<vector<int>> scores(P,vector<int> (S));
       vector<vector<int>> pupil(P,vector<int> (S));
       set<pair<int,int>> diff;
       for(int i=0;i<P;i++){
          map<int,int> hash;
          int a=0;
          for(int j=0;j<S;j++){
            cin>>scores[i][j];
            hash[scores[i][j]]=j;
          }
          for(int j=0;j<S;j++){
            cin>>pupil[i][j];
          }
          int prev=INT_MIN;
          for(auto &it:hash){
             int index=it.second;
             int current=pupil[i][index];
             if(prev>current) a++;
             prev=current;
          }
          diff.insert({a,i+1});
       }
       for(auto &it:diff){
          cout<<it.second<<endl;
       }
       
    }

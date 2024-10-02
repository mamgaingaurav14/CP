//https://www.codechef.com/problems/CHFADJSUM?tab=statement
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
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
       //solve;
       int n;
       cin>>n;
       vector<int> arr(n,0);
       for(int i=0;i<n;i++){
           cin>>arr[i];
       }
       if(n<=2) {
           no;
       }
       else{
           sort(arr);
           int last=arr[n-1];
           int seclast=arr[n-2];
           if(last!=seclast){
               if(arr[0]==seclast) {
                  no;
               }
               else yes;
               continue;
           }
           int count=0;
           for(int i=n-1;i>=0;i--){
               //count of last element
              if(arr[i]==last) count++;
              else break;
             }
                  int left=count-2;
                   int space_left=n-2;
                   if(space_left>=(left*2+1)){
                       yes;
                   }
                   else{
                       no;
                   }
            
           
       }
    }
}
       
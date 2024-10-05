
 
#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
#define lil long long int
 
     //write your code
     bool check2(vector<char> &x,vector<char> &y){
       pair<char,char> a={x[0],y[0]};
       bool flag=false;
       int index;
       for(int i=1;i<=3;i++){
        pair<char,char> b={y[i],x[i]};
        if(a==b){
          flag=true;
          index=i;
        } 
       }
       if(!flag) return false;
       if(index==1) {
        index=2;
       }
       else index=1;
        a={x[index],y[index]};
        flag=false;
       for(int i=index+1;i<=3;i++){
        pair<char,char> b={y[i],x[i]};
        if(a==b) flag=true;
       }
       if(!flag) return false;
       return true;
     }
   bool check(string a,string b){
   int size_a=a.size();
   int size_b=b.size();
   int diff=abs(size_a-size_b);
   if(size_a>size_b){
       while(diff--){
        b="0"+b;
      }
   }
   else if(size_b>size_a){
       while(diff--){
        a="0"+a;
      }
   }
   int cnt=0;
   vector<char > x(4),y(4);
   for(int i=0;i<a.size();i++){
      if(a[i]!=b[i]){
        cnt++;
        if(cnt>4) return false;
        x.push_back(a[i]);
        y.push_back(b[i]);
        if(cnt==4 ){
          if(check2(x,y)) return true;
          return false;
        }
      }
   }
   if(cnt<4) return false;
   return true;
}
 
 
     //write your code
 int countPairs(vector<int>& nums) {
        int n=nums.size();
        lil cnt=0;
        for(int i=0;i<nums.size();i++){
            string a=to_string(nums[i]);
            for(int j=i+1;j<n;j++){
               string b=to_string(nums[j]);
               if(a==b || check(a,b)){
                 cnt++;
               } 
            }
        }
        return cnt;
    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<int> nums={1,10,100};
    cout<<countPairs(nums);
}
 
 
//HARE KRISHNA HARE KRISHNA
//KRISHNA KRISHNA HARE HARE
//HARE RAMA HARE RAMA
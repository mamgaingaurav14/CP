#include <bits/stdc++.h>
using namespace std;

class decrease{
    public:
       bool operator()(const int &a,const int &b) const {
           return a>b;
       } 
    
};

class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        unordered_map <char,int> hash;
        for(int i=0;i<n;i++){
            hash[word[i]]++;
        }
        int x=hash.size();
        if(x<=8) return n;
        vector<int> dec;
        for(auto it:hash){
          dec.push_back(it.second);
        }
        sort(dec.begin(),dec.end(),decrease());
        int ans=0;
        int prod=1;
        int cnt=0;
        int size=dec.size();
        for(int i=0;i<size;i++){
          ans+=prod*dec[i];
          cnt++;
          if(cnt%8==0) prod++;
        }
        return ans;
    }
};

int main(){

}
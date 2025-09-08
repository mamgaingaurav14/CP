//basic making of a trie 
 #include <bits/stdc++.h>
using namespace std;
#define lil long long int
const int MOD=1e9+7;
 #define pb push_back
 #define sort(vec) sort(vec.begin(),vec.end())
class Trie {
public:
    vector<Trie*> places;
    bool flag;
    Trie() {
        int a=26;
        while(a--){
           places.push_back(NULL);
        } 
          flag=false;
    }
    
    void insert(string word) {
      Trie* temp=this;
        for(char c:word){
           if(temp->places[c-97]==NULL) temp->places[c-97]=new Trie();
           temp=temp->places[c-97];
        }
        temp->flag=true;
    }
    
    bool search(string word) {
      Trie* temp=this;
        for(char c:word){
           if(temp->places[c-97]==NULL) return false;
           temp=temp->places[c-97];
        }
        return temp->flag;
    }
    
    bool startsWith(string prefix) {
        Trie* temp=this;
        for(char c:prefix){
           if(temp->places[c-97]==NULL) return false;
           temp=temp->places[c-97];
        }
        return true;
    }
};
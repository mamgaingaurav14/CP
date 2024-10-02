 
#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
#define lil long long int

    string out(string in){
        string out;
        char x;
        for(char c:in){
           if(x!='z'){
            x=c+1;
           }
           else{
            x='a';
           }
           out.push_back(x);
        }
        return out;
     }
    char kthCharacter(long long k, vector<int>& operations) {
         string s="a";
         int x=0;
         while(pow(2,x)<k){
            x++;
         }
         long long index=0;
         while(x--){
            if(operations[index]%2){
              s+=out(s);
            }
            else{
               s+=s;
            }
            index++;
         }
         return s[k-1];
    }
int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    cout << minimizeRange(a) << endl;
    
    return 0;
}

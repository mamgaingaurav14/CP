//https://www.codechef.com/problems/ARRREM
#include <bits/stdc++.h>
using namespace std;
#define lil long long int
const int MOD = 1e9 + 7;

//my own code
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n, 0);
        int maxOre=0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            maxOre=(arr[i]|maxOre);
        }
        int bit=0;
        while(maxOre){
         if((maxOre&1)==0) break;
         maxOre>>=1;
         bit++;
         
         //aapne vo bit nikal li jis par zero aya 
       }
       int temp=bit;
       if(bit==32) cout<<"0"<<endl;
       //now i know at which bit it became zero
       else{
       int count=0;
       for(int i=0;i<n;i++){
           bit=temp+1;
          for(;bit<32;bit++){
              if(arr[i]&(1<<bit)){
                  count++;
                  break;
              }
          }
       }
       cout<<count<<endl;
    }
}
}

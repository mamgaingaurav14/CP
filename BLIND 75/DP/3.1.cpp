//climbing stairs question easy 
//tricky for fibonacci way
#include <bits/stdc++.h>
using namespace std;

//space optimization with tabulation
  int climbStairs(int n) {
       if(n<=2) return n;
       int prev1=1;
       int prev2=2;
       for(int i=3;i<=n;i++){
        int current=prev1+prev2;
        prev1=prev2;
        prev2=current;
       }
       return prev2;
    }
    int main(){

    }
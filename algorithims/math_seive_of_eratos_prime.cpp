#include <bits/stdc++.h>
using namespace std;
#define lil long long int 

//for finding all prime in range
//almost linear
int seive_of_eratosthenes(int n){
    vector<int> prime(n+1,1);
    int cnt=0;
    prime[1]=0;//1 is not a prime
    for(int i=2;i<=n;i++){
        if(prime[i]){
           cnt++;
          for(int j=i*i;j<=n;j+=i)
           prime[j]=0;
        }
    }
    return cnt;
}
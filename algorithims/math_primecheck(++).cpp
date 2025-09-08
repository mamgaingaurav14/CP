

#include <bits/stdc++.h>
using namespace std;
#define lil long long int
const int MOD=1e9+7;


//for one number 
bool isPrime(int n){
  // 6k ± 1 Optimization
  if(n<=1) return false;
  if(n<=3) return true;
  if(n%2==0 || n%3==0) return false;
  for (int i=5; i*i<=n; i+=6){
    if (n%i==0 || n%(i+2)==0) return false;
  }
  return true;
}

//for lot of numbers 
void Prime( ){
        int N=2000010;
	    vector<bool> isprime(N+1,true);
        vector<int> primes;
	    isprime[0]=isprime[1]=false;
	    for(int i=2;i*i<=N;i++)
	    {
	        if(isprime[i])
	        {
                primes.pb(i);
	            for(int j=i*i;j<=N;j+=i)
    	        {
    	            isprime[j]=false;
    	        }
	        }
	    }
}
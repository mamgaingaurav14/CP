//


#include <bits/stdc++.h>
using namespace std;
#define lil long long int 

//prime template 
   void Prime(){
        int N=2000010;
	    vector<bool> isprime(N+1,true);
        vector<int> primes;
	    isprime[0]=isprime[1]=false;
	    for(int i=2;i*i<=N;i++)
	    {
	        if(isprime[i])
	        {
                primes.push_back({});
	            for(int j=i*i;j<=N;j+=i)
    	        {
    	            isprime[j]=false;
    	        }
	        }
	    }
   }


   #include <bits/stdc++.h>
using namespace std;
#define lil long long int 

//generating primes at leet code
    int n = 35000;
    vector<lil> is_prime;
    vector<lil> primes;
    vector<lil> prime_squares;

    Solution() : is_prime(n + 1, 1) {
        is_prime[0] = is_prime[1] = 0; // 0 and 1 are not primes

        // Sieve of Eratosthenes
        for (lil i = 2; i <= n; i++) {
            if (is_prime[i]) {
                primes.push_back(i);
                for (lil j = i * i; j <= n; j += i) {
                    is_prime[j] = 0;
                }
            }
        }
    }
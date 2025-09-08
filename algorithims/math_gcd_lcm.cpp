

#include <bits/stdc++.h>
using namespace std;
#define lil long long int
const int MOD=1e9+7;

lil gcd(lil a, lil b) { return b == 0 ? a : gcd(b, a % b); }  // __gcd
lil lcm(lil a, lil b) { return ((a * b) / gcd(a, b)); }

  #include <bits/stdc++.h>
using namespace std;
#define lil long long int

//bin pow or pinary exponentian  0(logb) times
int pw(int a,int b,int m){
    if(b==0) return a%m;
    if(b%2==0){
        int t=pw(a,b/2,m);
        return (1ll*t*t)%m;
    }
    else{
         int t=pw(a,(b-1)/2,m);
         t=(1ll *t*t)%m;
         return (1ll*a*t%m);
    }
}

//mulitplicative inverse over mod m
int inv_b(int b,int m){
    return pw(b,m-2,m);
}



//2


        
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

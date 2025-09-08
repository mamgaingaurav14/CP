 #include <bits/stdc++.h>
using namespace std;
#define lil long long int

//maths functions 
int cnt_div_nrootn(int n){
    int cnt=0;
    for(int i=1;i*i<=n;i++){
       if(n%i==0) {
       cnt++;
       if(i!=n/i) cnt++;
       }
    }
    return cnt;
}



//direct functions 
//in c++ we can use __gcd(a,b);
int cnt_div_ofallnotill_nlogn(int n){
    vector<int> div(n+1);
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j+=i){
            div[j]++;
        }
    }
    for(int x:div)
     cout<<x<<endl;
}

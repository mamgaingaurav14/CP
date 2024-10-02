//HARE KRISHNA HARE KRISHNA
//KRISHNA KRISHNA HARE HARE
//HARE RAMA HARE RAMA
//RAMA RAMA HARE HARE


#include <bits/stdc++.h>
using namespace std;
#define lil long long int
const int MOD=1e9+7;
 #define pb push_back
 #define ppb pop_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
 #define yes cout<<"YES"<<'\n';
 #define no cout<<"NO"<<'\n';
const double PI=3.141592653589793238462;

// Macros
#define umap unordered_map
#define uset unordered_set
#define mset multiset

//binary search 
bool binary_search(vector<int> &arr,int target){
    int i=0;
    int j=arr.size()-1;
    while(i<=j){
        int mid=i+(j-i)/2;
        if(arr[mid]==target) return true;
        else if(arr[mid]<target){
          i=mid+1;
        }
        else{
            j=mid-1;
        }
    }
    return false;
}
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


lil gcd(lil a, lil b) { return b == 0 ? a : gcd(b, a % b); }  // __gcd
lil lcm(lil a, lil b) { return ((a * b) / gcd(a, b)); }

//custom decrement comaparator for map 
class decrease{
    public:
       bool operator()(const int &a,const int &b) const {
           return a>b;
       } 
    
};


 void solve(){
    
      int n;
      cin>>n;
       vector<int> arr(n,0);
       for(int i=0;i<n;i++){
           cin>>arr[i];
       }
     
     //write your code



 }
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
   int t;
   cin>>t;
    while(t--){
        solve();
    }
    
}

//HARE KRISHNA HARE KRISHNA
//KRISHNA KRISHNA HARE HARE
//HARE RAMA HARE RAMA
//RAMA RAMA HARE HARE
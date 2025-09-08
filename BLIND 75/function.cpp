#include <bits/stdc++.h>
using namespace std;
//functions for CP
#define yes cout<<"yes"<<endl;
 #define no cout<<"no"<<endl;
 #define bob cout<<"bob"<<endl;
 #define alice cout<<"alice"<<endl;
 if(flag) cout<<"BOB"<<endl;
 else cout<<"ALICE"<<endl;
 
  TreeNode* findLCA(TreeNode* root, int start, int end) {
        if(!root ||root->val==start|| root->val==end) return root;
        TreeNode* left = findLCA(root->left, start, end);
        TreeNode* right = findLCA(root->right, start, end);
        if(left && right) return root;
        return left?left:right;
    }
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

//tree depth dfs
int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);
        return 1+max(left,right);
    }

//bfs tree depth 
   int maxDepth(TreeNode* root) {
       queue<TreeNode*> q;
       if(root==NULL) return 0;
       q.push(root);
       int level=0;
       while(!q.empty()){
          level++;
          int size=q.size();
          while(size--){
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
          }
          
       }
       return level;
    }
bool perfect_no(lil x){
       x++;
       lil prod=1;
       for(lil i=0;i<18;i++){
           if(x/prod==0) break;
           prod*=2;
      }
      lil rem=x%(prod/2);
      if(rem==0) return true;
      return false;
   }
//reverse(string.begin(),string.end());
//https://www.codechef.com/practice-old
//https://iq.opengenus.org/cpp-template-for-competitive-coding/

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
int gcd(int a ,int b){
    if(a==0) return b;
    return gcd(b%a,a);
}

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

//mulitplicative inverse over mod m
int inv_b(int b,int m){
    return pw(b,m-2,m);
}

//hash function for pair class
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& p) const {
        auto hash1 = std::hash<T1>{}(p.first);
        auto hash2 = std::hash<T2>{}(p.second);
        return hash1 ^ hash2;  // Combine the two hashes
    }
};

//for vector hash 
struct vector_hash {
    std::size_t operator()(const std::vector<int>& v) const {
        std::size_t seed = 0;
        for (int i : v) {
            // Combine the hash of each element with the seed
            seed ^= std::hash<int>{}(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

//
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
                primes.push_back();
	            for(int j=i*i;j<=N;j+=i)
    	        {
    	            isprime[j]=false;
    	        }
	        }
	    }
   }

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


    //tries
    class Node {
public:
    Node* lists[26];
    bool flag = false;

};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(const string& word) {
        Node* node = root;
        for (char c : word) {
            int ch = c - 'a';
            if (!node->lists[ch]) {
                node->lists[ch] = new Node();
            }
            node = node->lists[ch];
            node->flag = true;
        }
    }

   
    vector<int> search(const string& target, int start) {
        vector<int> valid_lengths;
        Node* node = root;
        for (int i = start; i < target.length(); i++) {
            if (!node->lists[target[i] - 'a']) break;
            node = node->lists[target[i] - 'a'];
            if (node->flag) {
                valid_lengths.push_back(i - start + 1);
            }
        }
        return valid_lengths;
    }
};

//string steam
 istringstream iss(s1);
        string word;
        while(iss>>word){
          words[word]++;
        }

        
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
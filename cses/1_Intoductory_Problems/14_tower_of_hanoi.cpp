
 
#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
#define lil long long int
 //main approach sikhna hai yaha 
 //how to recursively shift elements from one tower to another 
 //using a middle tower 


     //write your code
  void solve(int n,int a,int b,int c){
    //a se c jana hai  using b 
    if(n==1){
        cout<<a<<" "<<c<<"\n";
        return;
    }
    solve(n-1,a,c,b);
    solve(1,a,b,c);
    solve(n-1,b,a,c);
 }
 //alternate function for finding exact which disk to use 
 /*long long solve(int n,int a,int b,int c,int top){
    //a se c jana hai  using b 
    if(n==1){
        cout<<"move disk "<<top<<" from rod "<<a<<" to rod "<<c<<endl;
        return 1;
    }
    return solve(n-1,a,c,b,1)+solve(1,a,b,c,n)+solve(n-1,b,a,c,1);
      }
*/
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
   lil n;
   cin>>n;
   int prev=1;
   for(int i=2;i<=n;i++){
    long long current=(prev*2)+1 ;
     prev=current;
   }
   cout<<prev<<"\n";
   solve(n,1,2,3);
}
 
 
//HARE KRISHNA HARE KRISHNA
//KRISHNA KRISHNA HARE HARE
//HARE RAMA HARE RAMA
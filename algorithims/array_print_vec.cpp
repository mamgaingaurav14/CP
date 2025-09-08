
#include <bits/stdc++.h>
using namespace std;
#define lil long long int
const int MOD=1e9+7;

void print_vec(vector<int> &values){
     for(int i:values) cout<<i<<" ";
     cout<<endl;

}
void print_vec(vector<vector<int>> &values){
     for(auto i:values){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
     }
}

#include <bits/stdc++.h>
using namespace std;

//easy pz question 
class Solution {
public:
    int countSeniors(vector<string>& details) {
           int n=details.size();
           int cnt=0;
        for(int i=0;i<n;i++){
        string age;
        age.push_back(details[i][11]);
        age.push_back(details[i][12]);
      int  num_age=stoi(age);
      if(num_age>60) cnt++;
        }
      return cnt;
    }
};
 int main(){
    return 0;
 }
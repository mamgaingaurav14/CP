#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count_5=0,count_10=0;
        for(int j:bills){
            if(j==5){
              count_5++;
            }
            else if(j==10){
               if(count_5<1) return false;
               count_5--;
               count_10++;
            }
            else{
               if(count_5<1 || count_10<1){
                  if(count_5<3) return false;
                 count_5-=3;
               }
               else {
                 count_5--;
                 count_10--;
               }
            }
        }
        return true;


    }
};
int main(){
    return 0;
}
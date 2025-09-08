/*
ot is very easy no
 need mentio na lot of details here
*/
//just these 2 functions

#include <bits/stdc++.h>
using namespace std;


int hammingWeight(int n) {
        int count=0;
        while(n){
           if(n&1) count++;
           n=n>>1;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> answer;
        for(int i=0;i<=n;i++){
            answer.push_back(hammingWeight(i));
        }
        return answer;
    }
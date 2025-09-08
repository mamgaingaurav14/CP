#include <bits/stdc++.h>
using namespace std;
//very easy question today 
    int minOperations(vector<string>& logs) {
        int count=0;
        for(int i=0;i<logs.size();i++){
           if( logs[i]=="../"){
             if(count) count--;
           }
           else if(logs[i]=="./"){
             continue;
           }
           else{
             count++;
           }
        }
        return count;
    }
int main(){

}
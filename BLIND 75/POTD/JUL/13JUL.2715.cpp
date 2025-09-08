#include <bits/stdc++.h>
using namespace std;
#define sort(vec) sort(vec.begin(),vec.end()) 
//very easy question today 

//the code we wrote first time was the right 
//code it just needed one single line addition
//and for finding that we were literally dping so many 
//things but it worked out in the end 
//lol 
   vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size()-1;
        //i need sorted positions firstly 
        unordered_map<int,int> hash;
        for(int i=0;i<=n;i++){
           hash[positions[i]]=i;
        }
        sort(positions);
        //now i travel in sorted positions
        stack<int> st;
        for(int i=0;i<=n;i++){
          int current=hash[positions[i]];
          if(!st.empty()){
            int prev=st.top();
            if(directions[prev]=='R'&& directions[current]=='L'){
               //collision
               if(healths[prev]>healths[current]){
                  healths[prev]--;
               }
               else if(healths[prev]<healths[current]){
                  healths[current]--;
                  st.pop();
                  i--;
               }
               else{
                 st.pop();
               }
            }
            else st.push(current);
          }
         else st.push(current);
        }
        vector<int> answer;
       while(!st.empty()){
        int current=st.top();
        answer.push_back(current);
        st.pop();
       }
       sort(answer);
       for(int i=0;i<answer.size();i++){
        answer[i]=healths[answer[i]];
       }
       return answer;
    }
int main(){
  return 0;
}
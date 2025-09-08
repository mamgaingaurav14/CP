#include <bits/stdc++.h>
using namespace std;


//direct one code using reverse function with iterators
 string reverseParentheses(string s) {
        stack<int> opening;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') opening.push(i);
            if(s[i]==')'){
                int temp=opening.top();
                opening.pop();
                reverse(s.begin()+ temp,s.begin()+i);
            }
        }
        string answer;
        for(char c:s){
          if(c!=')'&&c!='(') answer.push_back(c);
        }

        return answer;
    }

//solution 2
/*
    string reverseParentheses(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]==')'){
                queue<char> q;
                while(st.top()!='('){
                    char elment =st.top();
                    q.push(elment);
                    st.pop();
                }
                st.pop();
                while(!q.empty()){
                    st.push(q.front());
                    q.pop();
                }
            }
            else st.push(s[i]);
        }
        string answer;
        while(!st.empty()){
             answer.push_back(st.top());
             st.pop();
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
    */
int main(){
     string s = "(u(love)i)";
    cout<<reverseParentheses(s);
}
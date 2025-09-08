  #include <bits/stdc++.h>
using namespace std;

//recursion solution tle  
/*
int solve(string s,int x,int y,int score,int index){
        if(index!=-1) s.erase(index,2);
        bool nimila=true;
        int method1=-1e9;
        int method2=-1e9;
        int n=s.size();
        for(int i=0;i<n-1;i++){
            if(s[i]=='a' && s[i+1]=='b'){
                nimila=false;
             method1= solve(s,x,y,score+x,i);
            }
            if(s[i]=='b' && s[i+1]=='a'){
                nimila=false;
             method2= solve(s,x,y,score+y,i);
            }
        }
        if(nimila) return score;
        return max(method1,method2);
    }
    int maximumGain(string s, int x, int y) {
       return solve(s,x,y,0,-1);
    }
    int main(){
        string s = "aabbrtababbabmaaaeaabeawmvaataabnaabbaaaybbbaabbabbbjpjaabbtabbxaaavsmmnblbbabaeuasvababjbbabbabbasxbbtgbrbbajeabbbfbarbagha";
        int x = 8484,y = 4096;
        cout<<maximumGain(s,x,y);
    }
*/
//approaches giving tle 
    //chatgpt
    /*int solve(std::string s, int x, int y, std::unordered_map<std::string, int>& hash) {
    if (hash.find(s) != hash.end()) return hash[s];
    
    bool nimila = true;
    int method1 = 0;
    int method2 = 0;
    int n = s.size();
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'a' && s[i + 1] == 'b') {
            nimila = false;
            std::string newStr = s;
            newStr.erase(i, 2);
            method1 = std::max(method1, solve(newStr, x, y, hash) + x);
        }
        if (s[i] == 'b' && s[i + 1] == 'a') {
            nimila = false;
            std::string newStr = s;
            newStr.erase(i, 2);
            method2 = std::max(method2, solve(newStr, x, y, hash) + y);
        }
    }
    if (nimila) return hash[s] = 0;
    return hash[s] = std::max(method1, method2);
}

int maximumGain(std::string s, int x, int y) {
    std::unordered_map<std::string, int> hash;
    return solve(s, x, y, hash);
}*/

//now lets go and see solutions 

//method 1 
//stack approach using greedy
 int maximumGain(string s, int x, int y) {
        /*
        //The fundamental insight here is that 
        we should always try to remove the
         substring ('ab' or 'ba') that yields
          the higher points first.
          */
        stack<char> st;
        int score=0;
        for(char c:s){
            if(!st.empty()){
            if(x>y){
                if(st.top()=='a'&& c=='b'){
                    score+=x;
                    st.pop();
                    continue;
                }
            }
            else{
                if(st.top()=='b'&& c=='a'){
                    score+=y;
                    st.pop();
                    continue;
                }
            }
            }
            st.push(c);
        }
        string newstring;
        while(!st.empty()){
            newstring.push_back(st.top());
            st.pop();
        }
          reverse(newstring.begin(),newstring.end());
          for(char c:newstring){
            if(!st.empty()){
            if(x<y){
                if(st.top()=='a'&& c=='b'){
                    score+=x;
                    st.pop();
                    continue;
                }
            }
            else{
                if(st.top()=='b'&& c=='a'){
                    score+=y;
                    st.pop();
                    continue;
                }
            }
            }
            st.push(c);
        }
return score;

    }
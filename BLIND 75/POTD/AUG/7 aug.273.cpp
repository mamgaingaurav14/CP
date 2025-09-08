#include <bits/stdc++.h>
using namespace std;

    string ty(int num){
        int cnt=2;
        if(num==cnt) return "Twenty";
        cnt++;
        if(num==cnt) return "Thrity";
        cnt++;
        if(num==cnt) return "Forty";
        cnt++;
        if(num==cnt) return "Fifty";
        cnt++;
        if(num==cnt) return "Sixty";
        cnt++;
        if(num==cnt) return "Seventy";
        cnt++;
        if(num==cnt) return "Eighty";
        cnt++;
        if(num==cnt) return "Ninety";
        cnt++;
    }
        string teen(int num){
        int cnt=11;
        if(num==cnt) return "Eleven";
        cnt++;
        if(num==cnt) return "Twelve";
        cnt++;
        if(num==cnt) return "Thirteen";
        cnt++;
        if(num==cnt) return "Fourteen";
        cnt++;
        if(num==cnt) return "Fifteen";
        cnt++;
        if(num==cnt) return "Sixteen";
        cnt++;
        if(num==cnt) return "Seventeen";
        cnt++;
        if(num==cnt) return "Eighteen";
        cnt++;
        if(num==cnt) return "Nineteen";
        cnt++;
      }
      string one(int num){
        int cnt=0;
        if(num==cnt) return "";
        cnt++;
        if(num==cnt) return "One";
        cnt++;
        if(num==cnt) return "Two";
        cnt++;
        if(num==cnt) return "Three";
        cnt++;
        if(num==cnt) return "Four";
        cnt++;
        if(num==cnt) return "Five";
        cnt++;
        if(num==cnt) return "Six";
        cnt++;
        if(num==cnt) return "Seven";
        cnt++;
        if(num==cnt) return "Eight";
        cnt++;
        if(num==cnt) return "Nine";
        cnt++;
      }

      string helper(string num){
        string ans="";
        if(num[0]!='0') ans+=(one(num[0]-'0')) +" " + "Hundred" + " ";
        if(num[1]=='1'){
            string ey="";
            ey.push_back(num[1]);
            ey.push_back(num[2]);
           ans+=(teen(stoi(ey)));
           return ans;
        }
        if(num[1]=='0'){
           ans+=(one(num[2]-'0'));
           return ans;
        }
        ans+=(ty(num[1]-'0'));
        ans+= " " ;
        ans+=(one(num[2]-'0'));
         return ans;
        
      }
      
    string numberToWords(int num) {
        if(num==0) return "Zero";
        if(num<=9) return one(num);
        vector<string> arr={"","Hundred","Thousand","Million","Billion"};
       
        string str=to_string(num);
        int size=str.size();
        int diff=size%3;
        string to_add="";
        int lefti=diff?3-diff:0;
        while(lefti--){
            to_add.push_back('0');
        }
        int n=3-diff+size;
        int i=0;
        string ans="";
        int count=n/3;
        while(i+2<n){
            ans+=helper(str.substr(i,3)) + arr[count--];
            i+=3;
        }
      return ans;
        
    }

int main(){
    string ans=" ";
   cout<<ans[0];
   return 0;
}
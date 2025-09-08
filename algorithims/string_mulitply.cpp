 string add(string s1,string s2){
       string ans="";
     int carry=0;
      int n=s1.size()-1;int m=s2.size()-1;
      while(n>=0 && m>=0){
        int sum=carry+int(s1[n--]-'0')+int(s2[m--]-'0');
        ans.push_back(char('0'+sum%10));
        carry=sum/10;
      }
      while(n>=0){
        int sum=carry+int(s1[n--]-'0');
        ans.push_back(char('0'+sum%10));
        carry=sum/10;
      }
      while(m>=0){
        int sum=carry+int(s2[m--]-'0');
        ans.push_back(char('0'+sum%10));
        carry=sum/10;
      }
      while(carry){
         ans.push_back(char('0' + carry%10));
         carry=carry/10;
      }
      reverse(ans.begin(),ans.end());
      return ans;
     }
      string mul(int c,string s){
        string ans="";
        int carry=0;
        for(int i=s.size()-1;i>=0;i--){
        int digit=s[i]-'0';
        int sol=carry+(digit*c);
        ans.push_back(sol%10+'0');
        carry=sol/10;
        }
         while(carry){
         ans.push_back(char('0' + carry%10));
         carry=carry/10;
         }
         reverse(ans.begin(),ans.end());
         return ans;
     }
    string multiply(string num1, string num2) {
        string ans="";
        string end="";
        for(int i=num2.size()-1;i>=0;i--){
          ans=add(ans,mul(num2[i]-'0',num1)+end);
          end.push_back('0');
        }
        int i=0;
        int n=ans.size();
        for(int i=0;i<n;i++){
            if(ans[i]=='0') continue;
            return ans.substr(i,n-i+1);
        }
        return "0";
    }
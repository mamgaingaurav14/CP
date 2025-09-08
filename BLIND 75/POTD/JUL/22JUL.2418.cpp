//very ex pz dont attempt bitch
 vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
       unordered_map<int,string> hash;
       int n=names.size();
       for(int i=0;i<n;i++){
         hash[heights[i]]=names[i];
       }
       sort(heights.rbegin(),heights.rend());
       vector<string > answer;
       for(int i=0;i<n;i++){
         answer.push_back(hash[heights[i]]);
       }
       return answer;
    }
    
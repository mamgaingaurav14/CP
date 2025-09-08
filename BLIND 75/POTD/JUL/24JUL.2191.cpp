 //same as previous day question 
 //ivlovinf using of custom 
 //comparator
 
  vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
       unordered_map<int,int> hash;
       for(int i=0;i<nums.size();i++){
            string a="";
            string b=to_string(nums[i]);
            for(char c:b){
              int x=c-'0';
              a.push_back(char(mapping[x] + '0')); 
            }
            hash[nums[i]]=stoi(a);
        }
        sort(nums.begin(),nums.end(),[&hash](int a,int b){
           return hash[a]<hash[b];
        });
        return nums;
    }
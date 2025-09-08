 auto comp = [](const pair<int, int>& pp, const int val) {
    return pp.first < val;
     };

        

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int cnt=0,n=fruits.size();
        vector<pair<int,int>> vec;
        for(int i=0;i<n;i++){
            vec.push_back({baskets[i],i});
        }
        sort(vec.begin(),vec.end());
        for(int i=0;i<n;i++){
           int val=fruits[i];
           auto it=lower_bound(vec.begin(),vec.end(),val,comp);
           if(it!=vec.end()) vec.erase(it);
           else cnt++;
        }
        return cnt;
    }


int findpivot(vector<int> &nums){
       int i=0,n=nums.size(),j=n-1;
       if(n==1 || nums[j]>nums[0]) return 0;
       if(nums[j]<nums[j-1]) return j;
       while(i<j){
        int mid=(i+j)/2;
        if(nums[mid]<nums[mid-1] && nums[mid]<nums[mid+1]) return mid;
        else if(nums[mid]>nums[n-1]) i=mid+1;
        else j=mid;
       }
       return 0;
   }
    int search(vector<int>& nums, int target) {
        int pivot=findpivot(nums),n=nums.size();
        if(target<nums[pivot] | target>nums[(pivot-1+n)%n]) return -1;

        if(target<=nums[n-1])  {
            auto it=lower_bound(nums.begin()+pivot,nums.end(),target);
             if(it!=nums.end() && *it==target) return it-nums.begin();
        }
        else {
            auto it=lower_bound(nums.begin(),nums.begin()+pivot-1,target);
             if(it!=nums.end() && *it==target) return it-nums.begin();
        }
        return -1;
    }
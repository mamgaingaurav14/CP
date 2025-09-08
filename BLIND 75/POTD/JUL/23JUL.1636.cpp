
class Solution {
public:
    static unordered_map<int, int> hash;

    static bool compare(int a, int b) {
        if (hash[a] == hash[b]) {
            return a > b;
        }
        return hash[a] < hash[b];
    }

    vector<int> frequencySort(vector<int>& nums) {
        // Count frequencies
        for (int i : nums) {
            hash[i]++;
        }
        
        // Custom comparator for sorting
        sort(nums.begin(), nums.end(), compare);
        
        return nums;
    }
};

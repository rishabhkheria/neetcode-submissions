class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> results;

        for(int i =0 ; i < nums.size() && nums[i]<=0; i++){
            if(i==0 || nums[i] != nums[i-1]){
                twoSum2(nums, i, results);
            }
        }
        return results;
    }
    void twoSum2(vector<int> &nums, int i, vector<vector<int>> &results){
        int j = i+1;
        int k = nums.size()-1;

        // i, j and k shouldn't be equal
        while(j < k){
            int sum = nums[i]+ nums[j] + nums[k];
            if(sum < 0) j++;
            else if(sum > 0) k--;
            else {
                results.push_back({nums[i],nums[j],nums[k]});
                j++;
                k--;
                while(j < k && nums[j] == nums[j-1]) j++;
            }
        }

    }
};

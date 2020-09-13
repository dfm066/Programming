// #15. 3Sum :
// Given an array nums of n integers, are there elements a, b, c in nums such
// that a + b + c = 0? Find all unique triplets in the array which gives the sum
// of zero. Notice that the solution set must not contain duplicate triplets.

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> ans;
    if (nums.size() < 3)
      return ans;
    auto cmp = [](const vector<int> &a, const vector<int> &b) {
      return std::tie(a[0], a[1], a[2]) < std::tie(b[0], b[1], b[2]);
    };
    auto eql = [](const vector<int> &a, const vector<int> &b) {
      return std::tie(a[0], a[1], a[2]) == std::tie(b[0], b[1], b[2]);
    };
    int n = nums.size();
    std::sort(nums.begin(), nums.end());
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
    for (int i = 0; i < n - 2; ++i) {
      for (int j = i + 1; j < n - 1; ++j) {
        int k = 0 - nums[i] - nums[j];
        if (std::binary_search(nums.begin() + j, nums.end(), k)) {
          ans.push_back({nums[i], nums[j], k});
        }
      }
    }
    std::sort(ans.begin(), ans.end(), cmp);
    ans.erase(std::unique(ans.begin(), ans.end(), eql), ans.end());
    return ans;
  }
};
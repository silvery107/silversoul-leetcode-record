/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] Two Sum
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        return vector<int>{0};
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3};
    auto result = s.twoSum(nums,4);
    for(const auto& r:result){
        cout<<r<<' ';
    }
}
// @lc code=end


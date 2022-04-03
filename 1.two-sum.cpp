/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] Two Sum
 */
#include <vector>
#include <iostream>
// #include <hash_map>
#include <map>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // map<int, int> map;
        // <key, value>
        // map.find(key);
        // map.count(key); 
        // key matters, NOT value
        unordered_map <int, int> map;
        vector <int> ans;
        int diff = 0;

        for(int i=0;i<nums.size();i++){
            diff = target - nums[i];
            if(map.count(diff)){
                ans.push_back(map.find(diff)->second);
                ans.push_back(i);
                return ans;
            }
            else{
                map[nums[i]] = i;
            }
        }

        return ans;
    }
};

// int main(){
//     Solution s;
//     vector<int> nums = {2, 7, 11, 15};
//     auto result = s.twoSum(nums,9);
//     for(const auto& r:result){
//         cout<<r<<' ';
//     }
// }
// @lc code=end


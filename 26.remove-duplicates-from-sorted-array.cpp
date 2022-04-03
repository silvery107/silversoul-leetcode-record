/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1){
            return 1;
        }
        int i=0;
        int j=1;
        int cur_max = nums[0];
        while(j<nums.size()){
            if(cur_max==nums[j]){
                if(i==0){
                    i++;
                }
                j++;
            }else if(cur_max<nums[j]){
                if(i==0&&j==1){
                    i++;
                    continue;
                }
                if(nums[j]>cur_max){
                    cur_max = nums[j];
                }
                nums[i] = nums[j];
                i++;
                j++;
            }
        }
        return i;
    }
};
// @lc code=end


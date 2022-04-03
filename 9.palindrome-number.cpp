/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        if(x==0){
            return true;
        }
        int temp = 0;
        int len = 0;
        int total_len = 0;
        // vector<int> result;
        // while(x!=0){
        //     result.push_back(x%10);
        //     x /= 10;
        // }
        string result = to_string(x);
        total_len = result.size();
        if(result[total_len-1] == '0'){
            return false;
        }
        if (total_len%2==0){
            len = total_len/2;
        }
        else{
            len = (total_len-1)/2;
        }
        for(int i=0;i<len;i++){
            if (result[i]!=result[total_len-1-i]){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end


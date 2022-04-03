/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1){
            return strs[0];
        }
        int min_len = 201;
        int min_idx = -1;
        for(int i=0;i<strs.size();i++){
            if (min_len > strs[i].length()){
                min_len = strs[i].length();
                min_idx = i;
            }
        }
        if(min_len==0){
            return "";
        }
        string temp = "";
        int counter = 1;
        int pos = 0;
        for (int i=0;i<min_len;i++){
            temp = strs[min_idx].substr(0, counter);
            for (int j=0;j<strs.size();j++){
                pos = strs[j].find(temp);
                if(pos==string::npos || pos!=0){
                    if(counter==1){
                        return "";
                    }
                    else{
                        return strs[min_idx].substr(0, counter-1);
                    }
                }
            }
            counter += 1;
        }
        return strs[min_idx].substr(0, counter-1);
    }
};
// @lc code=end


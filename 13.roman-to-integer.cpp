/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        bool jump_flag = false;
        for(int i=0; i<s.length(); i++){
            if(jump_flag){
                jump_flag = false;
                continue;
            }
            switch (s[i])
            {
            case 'I':
                if(i<s.length()-1 && s[i+1]=='V'){
                    result += 4;
                    jump_flag = true;
                }else if(i<s.length()-1 && s[i+1]=='X'){
                    result += 9;
                    jump_flag = true;
                }else{
                    result += 1;
                }
                break;
            case 'V':
                result += 5;
                break;
            case 'X':
                if(i<s.length()-1 && s[i+1]=='L'){
                    result += 40;
                    jump_flag = true;
                }else if(i<s.length()-1 && s[i+1]=='C'){
                    result += 90;
                    jump_flag = true;
                }else{
                    result += 10;
                }
                break;
            case 'L':
                result += 50;
                break;
            case 'C':
                if(i<s.length()-1 && s[i+1]=='D'){
                    result += 400;
                    jump_flag = true;
                }else if(i<s.length()-1 && s[i+1]=='M'){
                    result += 900;
                    jump_flag = true;
                }else{
                    result += 100;
                }
                break;
            case 'D':
                result += 500;
                break;
            case 'M':
                result += 1000;
                break;
            default:
                break;
            }
        }
        return result;
    }
};
// @lc code=end


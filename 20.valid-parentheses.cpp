/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */
#include <string>
#include <stack>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> result;
        char temp;
        for (auto c:s){
            if(c=='\0'){
                break;
            }
            if(result.empty()){
                result.push(c);
            }else{
                temp = result.top();
                switch (temp)
                {
                case '(':
                    if(c==')'){
                        result.pop();
                    }else{
                        result.push(c);
                    }
                    break;
                case '[':
                    if(c==']'){
                        result.pop();
                    }else{
                        result.push(c);
                    }
                    break;
                case '{':
                    if(c=='}'){
                        result.pop();
                    }else{
                        result.push(c);
                    }
                    break;
                
                default:
                    return false;
                    break;
                }
            }
        }
        if(result.empty()){
            return true;
        }else{
            return false;
        }
    }
};
// @lc code=end


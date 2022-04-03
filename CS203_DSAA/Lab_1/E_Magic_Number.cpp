/*
Lihua defines Magic Number as that if you rotate the number 
180 degrees the number will not change. For example, 69, 96, 111, 181 
are magic numbers. 87, 76 are not. In particular, 0, 1, 8 will not change 
after 180 degrees rotation, 6 will change into 9 and 9 will change into 6, 
but 2 and 5 cannot change to each other or itself. 
Now Lihua wants to find the smallest and largest magic number in the range L to R.
*/
#include <iostream>
#include <vector>
using namespace std;
void find_n(int n, vector<string>& ans)
{
    if (n % 2 == 1) {
        ans.push_back("0");
        ans.push_back("1");
        ans.push_back("8");
    } else {
        ans.push_back("");
    }
    for (int i = n % 2 + 2; i <= n; i += 2) {
        vector<string> res;
        for (auto s : ans) {
            if (i != n)
                res.push_back("0" + s + "0");
            res.push_back("1" + s + "1");
            res.push_back("6" + s + "9");
            res.push_back("8" + s + "8");
            res.push_back("9" + s + "6");
        }
        ans = res;
    }
}
int main()
{
    long l, r;
    int n;
    long min_l, min_r;
    long result[2];
    int n_l, n_r;
    vector<string> ans;
    while (cin >> l >> r) {
        if(l==r)
            cout << l << " " << r << endl;
        min_l = min_r = r - l;
        string l_str, r_str;
        n_l = to_string(l).length();
        n_r = to_string(r).length();
        vector<string> temp;
        for (n = n_l; n <= n_r; n++) {
            find_n(n, temp);
            ans.insert(ans.end(), temp.begin(), temp.end());
            temp.clear();
        }
        for (auto a : ans) {
            long temp_num = stol(a);
            if (temp_num >= l && temp_num <= r && temp_num - l <= min_l) {
                min_l = temp_num - l;
                result[0] = temp_num;
            }
 
            if (temp_num >= l && temp_num <= r && r - temp_num <= min_r) {
                min_r = r - temp_num;
                result[1] = temp_num;
            }
        }
        cout << result[0] << " " << result[1] << endl;
        ans.clear();
    }
    return 0;
}
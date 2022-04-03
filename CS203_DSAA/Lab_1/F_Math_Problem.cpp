/*
Let S(X) be a function with variable X, it can be represented by 
the formula as S(X)=∑_j=1^X f(j), where f(x) consists of one or 
more functions in function set F={C,C/x,Csinx,Ccosx,C/sinx,C/cosx,C^x,Cx} 
with C is a constant integer ranging from 0 to 10^9.
*/
#include <iostream>
#include <string.h>
#include <string>
using namespace std;
int main()
{
    // int t; // [1, 10^4]
    // cin >> t;
    // cin.ignore();
    size_t t;
    string test;
    getline(cin, test);
    t = stoi(test);
    bool flag;
    for (int i = 0; i < t; i++) {
        flag = true;
        char str[200]; // [1, 100]
        cin.getline(str, 200);
        size_t l = strlen(str);
        for (int j = 0; j < l; j++) {
            if (j == 0) {
                if (str[j] != '0') {
                    flag = false;
                    break;
                }
            } else {
                if (str[j] == '+') {
                    if (str[j + 1] != '0') {
                        flag = false;
                        break;
                    }
                }
            }
        }
        if (flag)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}
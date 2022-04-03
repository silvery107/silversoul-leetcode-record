/*
Given n, please calculate S(n) where
S(n)=∑_i=1^n i∗(i+1)/2
*/
#include <iostream>
using namespace std;
int main()
{
    int T;
    cin >> T;
    unsigned long n;
    unsigned long result;
    for (int i = 0; i < T; i++) {
        cin >> n;
        result = (n*(n+1)*(2*n+1)+n*(n+1)*3)/12;
        cout << result << endl;
    }
    return 0;
}
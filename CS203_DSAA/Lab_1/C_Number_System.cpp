/*
Suppose in CS203, the number system only has three values 2,3,6. 
It holds 2<3<6. Given an integer n, please find the n-th smallest number 
in CS203 number system.
*/

#include <iostream>
 
using namespace std;
 
long ipow(long base, int exp)
{
    long result = 1;
    for (;;)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        if (!exp)
            break;
        base *= base;
    }
 
    return result;
}
 
int main()
{
    // 3^1 2 3 6
    // 3^2 22 23 26 32 33 36 62 63 66
    // 3^3 222 223 226 232 233 236 262 263 266 322 323 326 332 333 336 362 363 *366 622 623
    // 3^4 2222 2223 2226
 
    const int NUM[3] = {2, 3, 6};
    int T;
    cin >> T;
    int count = 0;
    int *list = new int[T];
    long result;
    int p,temp,idx;
    while (cin >> list[count++] && count < T)
        ;
    for (count = 0; count < T; count++)
    {
        result = 0;
        p = 1;
        while ((list[count] - ipow(3, p)) > 0)
        {
            list[count] -= ipow(3, p);
            p++;
        }
        for (; p > 1; p--)
        {
            temp = ipow(3, p - 1);
            idx = list[count] % temp == 0 ? list[count] / temp - 1 : list[count] / temp;
            result += NUM[idx] * ipow(10, p - 1);
            list[count] -= idx * temp;
        }
        idx = ((list[count] % 3) == 0 ? 3 : list[count] % 3) - 1;
        result += NUM[idx];
        cout << result << endl;
    }
 
    return 0;
}
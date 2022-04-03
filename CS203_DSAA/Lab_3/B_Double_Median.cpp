/*
Given a sequence {a1,a2,...,an} with n numbers.
Please output the double of the median of {a}.

*/
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    unsigned n;
    cin >> n;
    unsigned* a = new unsigned[n];
    for (unsigned i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << 2 * a[0] << endl;
        return 1;
    }
    random_shuffle(a, a + n);
    sort(a, a + n);
    if (n % 2 == 0) {
        cout << a[n / 2 - 1] + a[n / 2] << endl;
    } else {
        cout << 2 * a[(n + 1) / 2 - 1] << endl;
    }
    delete[] a;
    return 0;
}
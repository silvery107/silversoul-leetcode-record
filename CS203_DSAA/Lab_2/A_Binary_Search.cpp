/*
Given a nondecreasing sequence a with length n. 
We want to know whether integer x in the array a or not.
*/
#include <iostream>
using namespace std;
int binary_search(int*& a, int val, int left, int right)
{
    if (left > right)
        return -1;
    int mid = (left + right) / 2;
    if (a[mid] < val)
        binary_search(a, val, mid + 1, right);
    else if (a[mid] > val)
        binary_search(a, val, left, mid - 1);
    else
        return mid;
}
int main()
{
    int n, T, result;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> T;
    int* x = new int[T];
    for (int i = 0; i < T; i++) {
        cin >> x[i];
        if (n > 1)
            result = binary_search(a, x[i], 0, n - 1);
        else
            result = (a[0] == x[i]) ? 1 : -1;
        if (result != -1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    delete[] a;
    delete[] x;
    return 0;
}
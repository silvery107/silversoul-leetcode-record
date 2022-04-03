/*
Given a sequence {a} with  n different numbers (n is even). 
Please permutate this sequence to form a circle, 
so that each element on this circle is not equal to the average of two neighbors.
There may be more than one answer, you just need to print one of them.
*/
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int* nums = new int[n];
    for (int i = 0; i < n; i++)
        cin >> nums[i];
 
    // Sort and swap neighbours into small, big, small, big pattern
    sort(nums, nums + n);
    for (int i = 1; i < n; i += 2) {
        swap(nums[i], nums[i - 1]);
    }
 
    for (int i = 0; i < n; i++)
        cout << nums[i] << ' ';
    return 0;
}
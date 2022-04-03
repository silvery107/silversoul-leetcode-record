/*
Given an unsorted sequence, please sort it using 
insertion sort and selection sort respectively, 
and compare which algorithm is better.
We define the "swap two numbers" and "compare two numbers" are one operation. 
A sort algorithm is better means this algorithm 
can sort the target sequence with less operation. 
It's guaranteed that the numbers of operations of 
two algorithms are not the same in all test cases.
*/
#include <algorithm>
#include <iostream>
using namespace std;

int insertion_sort(int*& a, int len, int*& out)
{
    copy(a, a + len, out);
    int j, temp, count = 0;
    int left = 0, right = len - 1;
    for (int p = left + 1; p <= right; p++) {
        temp = out[p];
        for (j = p; j > left; j--) {
            count++;
            if (temp < out[j - 1]) {
                count++;
                out[j] = out[j - 1]; // equivalent swap
                // swap(out[j], out[j - 1]);
            } else {
                break;
            }
        }
        out[j] = temp; // count as the last step for swap
    }
    return count;
}
 
int selection_sort(int*& a, int len, int*& out)
{
    copy(a, a + len, out);
    int i, j, temp, count = 0;
    for (i = 0; i < len - 1; i++) {
        int min = i;
        for (j = i + 1; j < len; j++) {
            count++;
            if (out[j] < out[min]) {
                min = j;
            }
        }
        count++;
        swap(out[i], out[min]);
    }
    return count;
}
 
int main()
{
    int T, n;
    cin >> T;
    int insert_num, select_num;
    for (int i = 0; i < T; i++) {
        cin >> n;
        int* a = new int[n];
        for (int j = 0; j < n; j++)
            cin >> a[j];
        int* result = new int[n];
        insert_num = insertion_sort(a, n, result);
        for (int j = 0; j < n; j++) {
            cout << result[j] << ' ';
        }
        cout << endl;
        select_num = selection_sort(a, n, result);
        if (insert_num < select_num) {
            cout << "Insertion Sort wins!" << endl;
        } else {
            cout << "Selection Sort wins!" << endl;
        }
    }
 
    return 0;
}
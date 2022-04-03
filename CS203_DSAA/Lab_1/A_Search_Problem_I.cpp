/*
Given two arrays A with length n and B with length T. 
We want to know whether each element in array B is in array A or not.
*/
#include <iostream>
#include <set>
#include <hash_set>
 
using namespace std;
using namespace __gnu_cxx;
 
int main()
{
    int n;
    cin >> n;
    if (n == 0)
        return 1;
 
    hash_set<int> A;
    int count = 0;
    int temp;
    while (count++ < n && cin >> temp)
        A.insert(temp);
 
    int T;
    cin >> T;
    if (T == 0)
        return 1;
 
    int *B = new int[T];
    count = 0;
    while (count < T && cin >> B[count])
    {
        if (A.find(B[count]) == A.end())
            cout << "no" << endl;
        else
            cout << "yes" << endl;
        count++;
    }
 
    return 0;
}
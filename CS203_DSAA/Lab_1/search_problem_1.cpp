#include <iostream>
#include <string>
#include <vector>

using namespace std;

void split(string &str, const string &delim, vector<string> &result)
{
    size_t pos = 0;
    while ((pos = str.find(delim)) != string::npos)
    {
        result.push_back(str.substr(0, pos));
        str.erase(0, pos + delim.length());
    }
    result.push_back(str);
}

int main(int argc, char *argv[])
{

    string temp;
    getline(cin, temp);
    int n = stoi(temp);
    string A_str;
    getline(cin, A_str);
    vector<string> A;
    split(A_str, " ", A);

    getline(cin, temp);
    int T = stoi(temp);
    string B_str;
    getline(cin, B_str);
    vector<string> B;
    split(B_str, " ", B);

    bool flag = false;

    for (auto b : B)
    {
        flag = false;
        for (auto a : A)
        {
            if (!b.compare(a))
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
            cout << "no\n";
        else
            cout << "yes\n";
    }

    return 0;
}
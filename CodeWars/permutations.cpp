#include <bits/stdc++.h>
using namespace std;

vector<string> v;

void permutate(string str, string res)
{

    if (str.size() == 0)
    {
        v.push_back(res);
        return;
    }
    for (int i = 0; i < str.size(); i++)
    {
        rotate(str.begin(), str.begin() + 1, str.end());
        permutate(str.substr(1), res + str[0]);
    }
}

vector<string> permutations(string s)
{
    permutate(s, "");
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << "  ";
    cout << endl;
    //Removing Dupes
    sort(v.begin(), v.end());
    auto it = unique(v.begin(), v.end());
    v.resize(distance(v.begin(), it));
    vector<string> temp = v;
    v.clear();
    return temp;
}

int main()
{
    vector<string> ans = permutations("aabc");
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << "  ";
    return 0;
}
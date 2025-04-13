#include <bits/stdc++.h>
using namespace std;

int lcs(int i, int j, string &s1, string &s2)
{
    if (i < 0 || j < 0)
        return 0;
    // remove 1 char from s1
    int ans = lcs(i - 1, j, s1, s2);
    // remove 1 char from s2
    ans = max(ans, lcs(i, j - 1, s1, s2));
    // remove 1 char from s1 & s2
    ans = max(ans, lcs(i - 1, j - 1, s1, s2) + (s1[i] == s2[j]));
    return ans;
}
int main()
{
    string s1, s2;
    cout << "Enter the first string: ";
    cin >> s1;
    cout << "Enter the second string: ";
    cin >> s2;
    cout << "Length of LCS is " << lcs(s1.size() - 1, s2.size() - 1, s1, s2);
}
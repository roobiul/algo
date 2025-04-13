#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number :";
    cin >> n;
    int m[n][n];
    memset(m, 0, sizeof(m));
    int r;
    int c;
    int k = n * n;
    int i, j;
    for (r = 0; r < n; r++)
        for (c = 0; c < n; c++)
            m[r][c] = k--;
    for (r = 0; r < n / 4; r++)
        for (c = 0; c < n / 4; c++)
            m[r][c] = n * r + c + 1;
    for (r = 0; r < n / 4; r++)
        for (c = n - (n / 4); c < n; c++)
            m[r][c] = n * r + c + 1;
    for (r = n - (n / 4); r < n; r++)
        for (c = 0; c < n / 4; c++)
            m[r][c] = n * r + c + 1;
    for (r = n - (n / 4); r < n; r++)
        for (c = n - (n / 4); c < n; c++)
            m[r][c] = n * r + c + 1;
    for (r = n / 4; r < n - (n / 4); r++)
        for (c = n / 4; c < n - (n / 4); c++)
            m[r][c] = n * r + c + 1;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            cout << setw(5) << m[i][j] << " ";
        cout << endl;
    }
}

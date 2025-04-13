#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Function to compute matrix chain multiplication order
void matrixChainOrder(vector<int> &p, vector<vector<int>> &m, vector<vector<int>> &s)
{
    int n = p.size() - 1;

    // Initialize m and s matrices
    m.assign(n, vector<int>(n, 0));
    s.assign(n, vector<int>(n, 0));

    for (int chain_len = 2; chain_len <= n; ++chain_len)
    { // Chain length from 2 to n
        for (int i = 0; i < n - chain_len + 1; ++i)
        {
            int j = i + chain_len - 1;
            m[i][j] = numeric_limits<int>::max();
            for (int k = i; k < j; ++k)
            {
                int q = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

// Function to print the optimal parenthesization
void printOptimalParens(vector<vector<int>> &s, int i, int j)
{
    if (i == j)
    {
        cout << "A" << i + 1;
    }
    else
    {
        cout << "(";
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j] + 1, j);
        cout << ")";
    }
}

int main()
{
    vector<int> p = {30, 35, 15, 5, 10}; // Example dimensions
    int n = p.size() - 1;
    vector<vector<int>> m, s;

    matrixChainOrder(p, m, s);

    cout << "Minimum number of multiplications: " << m[0][n - 1] << endl;
    cout << "Optimal Parenthesization: ";
    printOptimalParens(s, 0, n - 1);
    cout << endl;

    return 0;
}
// بسم الله الرحمن الرحيم
// محمد روبيول الإسلام
// roobiul~Githab

#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <vector>
#define ll long long int
#define ctt cout <<
#define Robiul                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;

int knapsack(int W, int weights[], int values[], int n)
{
    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][W];
}

int main()
{
    int n, W;

    cout << "Enter maximum weight capacity of knapsack: ";
    cin >> W;
    cout << "Enter number of items: ";
    cin >> n;

    int weights[n], values[n];

    cout << "Enter weights of items: ";
    for (int i = 0; i < n; i++)
        cin >> weights[i];

    cout << "Enter values of items: ";
    for (int i = 0; i < n; i++)
        cin >> values[i];

    cout << "Maximum value in Knapsack: " << knapsack(W, weights, values, n) << endl;

    return 0;
}

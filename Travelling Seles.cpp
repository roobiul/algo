#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define INF INT_MAX
int n;
vector<vector<int>> cost;
vector<vector<int>> dp;

// TSP using DP with Bitmasking
int tsp(int mask, int pos)
{
    if (mask == (1 << n) - 1)
        return cost[pos][0]; // Return to start

    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INF;
    for (int city = 0; city < n; city++)
    {
        if (!(mask & (1 << city)))
        { // If city is not visited
            int newAns = cost[pos][city] + tsp(mask | (1 << city), city);
            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}

int main()
{
    n = 4; // Number of cities
    cost = {{0, 16, 11, 6}, {8, 0, 13, 16}, {4, 7, 0, 9}, {5, 12, 2, 0}};
    dp.assign(1 << n, vector<int>(n, -1));

    cout << "Minimum travel cost: " << tsp(1, 0) << endl;
    return 0;
}
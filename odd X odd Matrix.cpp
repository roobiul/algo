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

void generateMagicSquare(int n)
{
    int magicSquare[n][n] = {0};
    memset(magicSquare, 0, sizeof(magicSquare));

    int row = 0, col = n / 2;

    for (int num = 1; num <= n * n; num++)
    {
        magicSquare[row][col] = num;

        int newRow = (row - 1 + n) % n;
        int newCol = (col + 1) % n;

        if (magicSquare[newRow][newCol] != 0)
        {
            row = (row + 1) % n;
        }
        else
        {
            row = newRow;
            col = newCol;
        }
    }

    cout << "Magic Square of size :" << n << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << magicSquare[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Size of the magic square :"<<endl;
    cin >> n;

    generateMagicSquare(n);
    return 0;
}

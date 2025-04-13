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

struct Point
{
    int x, y;
};

// Function to find the orientation of three points
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0)
        return 0;             // Collinear
    return (val > 0) ? 1 : 2; // Clockwise or Counterclockwise
}

// Function to compute the convex hull using Jarvis March algorithm
void convexHull(Point points[], int n)
{
    // If there are less than 3 points, no convex hull is possible
    if (n < 3)
        return;

    // Initialize the result array to store the convex hull
    Point hull[n];
    int hullSize = 0;

    // Find the leftmost point
    int leftmost = 0;
    for (int i = 1; i < n; i++)
    {
        if (points[i].x < points[leftmost].x)
        {
            leftmost = i;
        }
    }

    // Start from the leftmost point and move counterclockwise
    int p = leftmost, q;
    do
    {
        // Add the current point to the hull
        hull[hullSize++] = points[p];

        // Find the next point in the hull
        q = (p + 1) % n;
        for (int i = 0; i < n; i++)
        {
            // If point i is more counterclockwise than q, update q
            if (orientation(points[p], points[i], points[q]) == 2)
            {
                q = i;
            }
        }

        // Set p as q for the next iteration
        p = q;

    } while (p != leftmost); // Repeat until we return to the starting point

    // Print the convex hull
    cout << "Convex Hull Points:\n";
    for (int i = 0; i < hullSize; i++)
    {
        cout << "(" << hull[i].x << ", " << hull[i].y << ")\n";
    }
}

int main()
{
    // Example set of points
    Point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    int n = sizeof(points) / sizeof(points[0]);

    // Compute and print the convex hull
    convexHull(points, n);

    return 0;
}
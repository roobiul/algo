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

// #include <algorithm>
// #include <stack>
using namespace std;

struct Point
{
    int x, y;
};

// A global point needed for sorting points with reference to the first point
Point p0;

// Utility function to find the next-to-top element in the stack
Point nextToTop(stack<Point> &s)
{
    Point top = s.top();
    s.pop();
    Point nextTop = s.top();
    s.push(top);
    return nextTop;
}

// Swap two points
void swap(Point &p1, Point &p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

// Compute the squared distance between two points
int distSq(Point p1, Point p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

// Find the orientation of the triplet (p, q, r)
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0)
        return 0;             // Collinear
    return (val > 0) ? 1 : 2; // Clockwise or Counterclockwise
}

// Compare function for sorting points
bool compare(Point p1, Point p2)
{
    int o = orientation(p0, p1, p2);
    if (o == 0)
        return (distSq(p0, p2) >= distSq(p0, p1));
    return (o == 2);
}

// Graham Scan algorithm to find the convex hull
void grahamScan(Point points[], int n)
{
    // Find the bottom-most point (or leftmost if there are ties)
    int ymin = points[0].y, minIndex = 0;
    for (int i = 1; i < n; i++)
    {
        int y = points[i].y;
        if ((y < ymin) || (ymin == y && points[i].x < points[minIndex].x))
        {
            ymin = points[i].y;
            minIndex = i;
        }
    }

    // Place the bottom-most point at the first position
    swap(points[0], points[minIndex]);

    // Sort the remaining points based on polar angle
    p0 = points[0];
    sort(points + 1, points + n, compare);

    // Initialize the stack
    stack<Point> s;
    s.push(points[0]);
    s.push(points[1]);
    s.push(points[2]);

    // Process the remaining points
    for (int i = 3; i < n; i++)
    {
        while (s.size() > 1 && orientation(nextToTop(s), s.top(), points[i]) != 2)
            s.pop();
        s.push(points[i]);
    }

    // Print the convex hull
    cout << "Convex Hull Points:\n";
    while (!s.empty())
    {
        Point p = s.top();
        cout << "(" << p.x << ", " << p.y << ")\n";
        s.pop();
    }
}

int main()
{
    Point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    int n = sizeof(points) / sizeof(points[0]);

    grahamScan(points, n);

    return 0;
}
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

// Compute the cross product to determine the relative position of a point
int crossProduct(Point p1, Point p2, Point p)
{
    return (p.y - p1.y) * (p2.x - p1.x) - (p2.y - p1.y) * (p.x - p1.x);
}

// Compute distance of point p from line p1-p2
int distance(Point p1, Point p2, Point p)
{
    return abs(crossProduct(p1, p2, p));
}

// Recursive function to find convex hull
void findHull(vector<Point> &points, Point p1, Point p2, int side, vector<Point> &hull)
{
    int maxDist = 0, index = -1;

    for (int i = 0; i < points.size(); i++)
    {
        int dist = distance(p1, p2, points[i]);
        if (crossProduct(p1, p2, points[i]) == side && dist > maxDist)
        {
            index = i;
            maxDist = dist;
        }
    }

    if (index == -1)
    { // No point found, add endpoints to hull
        hull.push_back(p1);
        hull.push_back(p2);
        return;
    }

    findHull(points, points[index], p1, -crossProduct(points[index], p1, p2), hull);
    findHull(points, points[index], p2, -crossProduct(points[index], p2, p1), hull);
}

vector<Point> convexHull(vector<Point> &points)
{
    vector<Point> hull;
    if (points.size() < 3)
        return hull;

    // Find leftmost and rightmost points
    Point left = points[0], right = points[0];
    for (auto p : points)
    {
        if (p.x < left.x)
            left = p;
        if (p.x > right.x)
            right = p;
    }

    // Find hull points on both sides of the line
    findHull(points, left, right, 1, hull);
    findHull(points, left, right, -1, hull);

    return hull;
}

int main()
{
    vector<Point> points = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    vector<Point> hull = convexHull(points);

    cout << "Convex Hull:\n";
    for (auto p : hull)
    {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }
    return 0;
}

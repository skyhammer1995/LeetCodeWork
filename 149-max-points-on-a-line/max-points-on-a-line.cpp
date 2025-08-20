    // cross product is: (x2 - x1)(y3 - y1) - (y2 - y1)(x3 - x1) = 0, 
    // if result is 0 then the 3-points are collinear. So how to translate this?
    // (x2 - x1)(y3 - y1) = (y2 - y1)(x3 - x1)
    // so we know <Point1, Point2> and <Point1, Point3> are linearly dependent.
    // Thus for multiple points:
    // (x2 - x1)(yi - y1) = (y2 - y1)(xi - x1)
    // In other words, we're using the first two collinear points as reference, with each subsequent point.
    // But that does make it mega inefficient, and we'd need to check every pair, with each other point, so that gets to like
    // O(n^3) I think, which obviously is not ideal

class Solution {
public:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    int maxPoints(vector<vector<int>>& points) {
    int n = points.size();
    if (n <= 2) return n;

    int maxCount = 0;

    for (int i = 0; i < n; ++i) {
        unordered_map<string, int> dirCount;
        int curMax = 0;

        for (int j = 0; j < n; ++j) {
            if (i == j) continue;

            int dx = points[j][0] - points[i][0];
            int dy = points[j][1] - points[i][1];
            int g = gcd(dx, dy);
            dx /= g;
            dy /= g;

            // Encode as string to handle signs consistently
            string key = to_string(dx) + "/" + to_string(dy);
            dirCount[key]++;
            curMax = max(curMax, dirCount[key]);
        }
        maxCount = max(maxCount, curMax + 1); // +1 for the reference point
    }

    return maxCount;
    }
};
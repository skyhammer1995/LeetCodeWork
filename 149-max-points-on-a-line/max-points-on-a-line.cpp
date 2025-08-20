// cross product is: (x2 - x1)(y3 - y1) - (y2 - y1)(x3 - x1) = 0, 
// if result is 0 then the 3-points are collinear. So how to translate this?
// (x2 - x1)(y3 - y1) = (y2 - y1)(x3 - x1)
// so we know <Point1, Point2> and <Point1, Point3> are linearly dependent.
// Thus for multiple points:
// (x2 - x1)(yi - y1) = (y2 - y1)(xi - x1)
// In other words, we're using the first two collinear points as reference, with each subsequent point.
// But that does make it mega inefficient, and we'd need to check every pair, with each other point, so that gets to like
// O(n^3) I think, which obviously is not ideal


// for sake of seeing optimal solutions, I'm gonna see what an LLM has to say and pass it in as a solution here,
// so I can see this maybe without string conversion
class Solution {
public:
// Helper function to compute gcd
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int maxPoints(vector<vector<int>>& points) {
    int n = points.size();
    if (n <= 2) return n; // 0,1,2 points are trivially collinear

    int maxCount = 0; // stores the global maximum number of points on a line

    for (int i = 0; i < n; ++i) { // reference point
        unordered_map<pair<int,int>, int, 
            function<size_t(pair<int,int>)>> slopeCount(0, 
            [](pair<int,int> p){ return hash<long long>()(((long long)p.first) << 32 | (unsigned int)p.second); }
        );

        int curMax = 0; // max number of points sharing the same slope from i

        for (int j = 0; j < n; ++j) { // all other points
            if (i == j) continue;

            int dx = points[j][0] - points[i][0];
            int dy = points[j][1] - points[i][1];

            int g = gcd(dx, dy);
            dx /= g;
            dy /= g;

            // Ensure consistent direction: keep dx positive
            if (dx < 0) {
                dx = -dx;
                dy = -dy;
            } else if (dx == 0 && dy < 0) { // vertical line
                dy = -dy;
            }

            pair<int,int> slope = {dy, dx};
            slopeCount[slope]++;
            curMax = max(curMax, slopeCount[slope]);
        }

        maxCount = max(maxCount, curMax + 1); // +1 for reference point
    }

    return maxCount;
}
};
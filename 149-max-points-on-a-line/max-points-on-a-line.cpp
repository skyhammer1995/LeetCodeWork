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
    int maxPoints(vector<vector<int>>& pt) {
        int ans=1; 
        int n=pt.size();
       // slope of every point with selected point
        for(int i=0;i<n-1;i++){
            map<double,int> mp;
            for(int j=i+1;j<n;j++){
                //calculating the slope
                double x = (double)(pt[j][1]-pt[i][1])/(double)(pt[j][0]-pt[i][0]);
                if((pt[j][0]-pt[i][0])==0 ) //infinite slop for Perpendicular line
                    mp[abs(x)]++; 
                else
               //storing the slop into map
                    mp[x]++;
            }
            // same slope w.r.t.that selected point
            int temp = 0;
            for(auto it:mp)
                temp = max(temp, it.second+1);    // +1 for the current point(point itself)
            ans = max(temp, ans);
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [&](const std::vector<int>& a, const std::vector<int>& b) { return a[0] < b[0]; });
        for (std::vector<vector<int>>::iterator interval = intervals.begin(); interval != intervals.end();) {
            std::vector<vector<int>>::iterator next = std::next(interval);
            if (next != intervals.end()) {
                if (interval->back() >= next->front() &&
                    interval->back() < next->back()) {
                    // combine/merge intervals[i] and intervals[i+1]
                    vector<int> tmp;
                    tmp.push_back((*interval).front());
                    tmp.push_back((*next).back());
                    *interval = tmp;
                    next = intervals.erase(next);
                } else if ((interval->front() <= next->front()) && 
                           (interval->back() >= next->back())) {
                    next = intervals.erase(next);
                } else {
                    ++interval;
                }
            } else {
                ++interval;
            }
        }
        return intervals;
    }
};
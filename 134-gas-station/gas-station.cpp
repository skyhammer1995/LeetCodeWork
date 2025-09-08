class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0; // total net gas across all stations
        int currentGas = 0; // current tank while simulating a section
        int solution = 0; 

        for (int i = 0; i < gas.size(); ++i) {
            int difference = gas[i] - cost[i];
            total += difference;
            currentGas +=  difference;
            
            if (currentGas < 0) {
                // we can't reach station i + 1
                solution = i + 1;
                currentGas = 0;
            }
        }

        // Was suggested to just do this, makes sense for handling when we're at size
        return total < 0 ? -1 : solution;
    }
};
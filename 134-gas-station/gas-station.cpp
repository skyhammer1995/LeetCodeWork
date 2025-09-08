class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0; // total net gas across all stations
        int currentGas = 0; // current tank while simulating a section
        int solution = 0; 

        // Start at where gas[i] is max? If we ever get to a point where cost[i] > currentGas, we have to return -1?
        // could it be even simpler to say, the sum of all elements in vector gas, and cost, we know we can go around the circuit?

        // Intuition: Ok, stepping through the first example, I think we can just start at 0, keep a running sum:
        // current gas + gas[i] - current[i];
        // once that sum equates to 0 (or greater), we can choose i as our starting index (I think). We may need to get to the end of the arrays
        // otherwise, if we never hit 0 or greater, we can return -1

        // Ok, more greedy research, we need to just consider that 'if we ever hit where the tank < 0, any stations between last solution, and current i would not have worked.
        
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
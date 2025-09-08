class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int currentGas = 0;
        int minimumGas = INT_MAX;
        int gasSize = gas.size(); // we know gas.length()==cost.length(), no need to get both right now
        
        int solution = 0; // After working through the failed case, we just need to find where the minimum gas would be. If we have any case where cost total exceeds gas total, we know we need to return -1

        // Start at where gas[i] is max? If we ever get to a point where cost[i] > currentGas, we have to return -1?
        // could it be even simpler to say, the sum of all elements in vector gas, and cost, we know we can go around the circuit?

        // Intuition: Ok, stepping through the first example, I think we can just start at 0, keep a running sum:
        // current gas + gas[i] - current[i];
        // once that sum equates to 0 (or greater), we can choose i as our starting index (I think). We may need to get to the end of the arrays
        // otherwise, if we never hit 0 or greater, we can return -1     
        
        for (int i = 0; i < gasSize; ++i) {
            currentGas +=  gas[i] - cost[i];

            // find where difference is lowest
            if (currentGas <= minimumGas) {
                solution = i;
                minimumGas = currentGas;
            }
        }

        if (currentGas < 0) {
            // Total gas < total cost, i.e. we never were able to get a starting point, return -1
            return -1;
        }
        
        // Was suggested to just do this, makes sense for handling when we're at size
        return (solution + 1) % gasSize;
    }
};
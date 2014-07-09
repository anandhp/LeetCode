/**
    
    There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
    
    You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to 
    its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
    
    Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
    
    Note:
    The solution is guaranteed to be unique.

**/

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int N = gas.size();
        int excessGas = 0;
        int startStation = 0;
        for (int i = startStation; startStation < N;) {
            excessGas += gas[i%N] - cost[i%N];
            if (excessGas < 0) {
                startStation = ++i;
                excessGas = 0;
                continue;
            }else {
                i++;
                if (i % N == startStation)
                    break;
            }
        }
        if (startStation < N)
            return startStation;
        return -1;
    }
};
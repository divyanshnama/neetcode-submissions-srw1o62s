class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumgas = 0;
        for (auto i : gas) sumgas += i;
        int sumcost = 0;
        for (auto i : cost) sumcost += i;
        if (sumcost > sumgas) return -1;
        int start = 0;
        int currgas = 0;
        int n = gas.size();
        for (int i = 0; i < n; i++) {
            currgas += gas[i] - cost[i];
            if (currgas < 0) {
                start = i + 1;
                currgas = 0;
            }
        }
        return start;
    }
};

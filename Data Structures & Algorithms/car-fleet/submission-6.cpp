class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> cars;

        for (int i =0;i<speed.size();i++)
        {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i],time});
        }

        sort(cars.rbegin(),cars.rend());

        double prevTime =0;
        double currTime;
        int fleet =0;
        for(int i =0;i<speed.size();i++)
        {
            currTime = cars[i].second;
            if(currTime>prevTime){
                fleet++;
            prevTime= currTime;
            }
        }
        return fleet;
    }
};

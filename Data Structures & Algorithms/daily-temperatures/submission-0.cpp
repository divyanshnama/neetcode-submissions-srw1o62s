class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result;
        for(int  i=0 ; i< temperatures.size();i++)
        {
            int curr = temperatures[i];
            for(int  j =i+1;j<temperatures.size();j++ )
            {
                if(temperatures[j]>curr)
                {
                    result.push_back(j-i);
                    break;
                } 
                if (j==temperatures.size()-1) result.push_back(0);    
            }
            
        }
        result.push_back(0);
        return result;
    }
};

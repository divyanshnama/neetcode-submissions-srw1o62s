class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n  = temperatures.size();
        vector<int> ans(n,0);
        int hottest  = INT_MIN;
        for(int i =n-1;i>=0;i--)
        {
            if(hottest<= temperatures[i])
                hottest = temperatures[i];
            else 
            {
                int it=i+1;
                while(temperatures[it] <= temperatures[i])
                {
                    it = it +ans[it];
                }

                ans[i]= it-i;
            }
   
        }
        return ans;



        // vector<int> ans;
        // stack<int> st;
        // int n =temperatures.size()-1;

        // for(int i =n;i>=0;i-- )
        // {
        //     while(!st.empty() && temperatures[st.top()]<=temperatures[i])
        //     {
        //         st.pop();
        //     }
        //     if(st.empty())
        //     { 
        //         st.push(i);
        //         ans.push_back(0);
        //     }
        //     else
        //     {
        //         ans.push_back(st.top()-i); 
        //         st.push(i);
        //     }

        // }
        // reverse(ans.begin(),ans.end());
        // return ans;
        
    }
};

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       vector<int> temp;
       vector<vector<int>> ans;
       sort(candidates.begin(), candidates.end());
       int sum =0;
        solve (candidates,target,0,temp,ans,sum);
        return ans ;
    }

    void solve(vector<int>& candidates, int target,int i,vector<int> temp,
            vector<vector<int>>& ans,int sum)
            {
                if (target==sum)
                {
                    ans.push_back(temp);
                    return;
                }
                if(sum> target || i == candidates.size())
                    return;

                 //take current element
                temp.push_back(candidates[i]);
                solve (candidates,target,i+1,temp,ans,sum + candidates[i]);
                temp.pop_back();   // Backtrack

                while(i+1< candidates.size() && candidates[i]==candidates[i+1]) i++;
                // Don't take current element
                solve (candidates,target,i+1,temp,ans,sum);

               

            }
};

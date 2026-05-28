class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int maxi = findMax(piles);
        int low  =1;
        int high = maxi;
        int ans =0;
        while(low<=high)
        {
            int mid = low +(high-low)/2;
            
            int totalHours = totalhours(piles,mid);
            if(totalHours<=h){
                high =mid-1;
                ans = mid;
            }
            else
                low =mid +1;
        }
        return ans ;
    }

    int findMax(vector<int>& piles)
    {
        int maxi =INT_MIN;
        for(int  i= 0;i<piles.size();i++)
        {
            maxi = max(maxi,piles[i]);
        }
        return maxi;
    }
    int totalhours(vector<int>& piles,int mid )
    {
        int totalHours =0;
        for(int i =0;i<piles.size();i++)
        {
            totalHours += ceil((double)piles[i]/(double)mid);
        }
        return totalHours;
    }


};

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        if (hand.size() % groupSize != 0)
            return false;

        map<int, int> freq;

        for (auto i : hand)
            freq[i]++;

        for (auto [card, count] : freq) {

            if (count == 0)
                continue;

            for (int x = card; x < card + groupSize; x++) {

                if (freq[x] < count)
                    return false;

                freq[x] -= count;
            }
        }

        return true;
    }
};

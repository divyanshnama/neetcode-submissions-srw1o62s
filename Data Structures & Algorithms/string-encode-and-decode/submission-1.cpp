class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for(auto i:strs)
        {
            encoded += to_string(i.size()) + '#' + i;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i=0;
        while(i<s.size())
        {
            int j =i;
            while(s[j]!='#')
            {
                j++;
            }
            int length = stoi(s.substr(i,j-i));

            decoded.push_back(s.substr(j+1,length));
            i=length+j+1;
        }
        return decoded;
    }
};

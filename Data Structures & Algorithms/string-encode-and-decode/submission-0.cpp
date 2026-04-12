class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for(auto str : strs )
        {

            encoded += to_string(str.size()) + "#" + str;
        }
        cout<<encoded;
        return encoded;
    }

    vector<string> decode(string s) {
        int i =0;
        vector<string> result;
        while(i<s.size())
        {
            int j =i;
            while (s[j]!='#')
                j++;

            int length = stoi(s.substr(i,j-i));
            result.push_back(s.substr(j+1,length));
            i=length+j+1;
        }
        return result ;
    }
};

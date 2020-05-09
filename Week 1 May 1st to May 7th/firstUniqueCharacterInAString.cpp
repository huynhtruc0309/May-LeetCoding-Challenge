class Solution {
public:
    int firstUniqChar(string s) 
    {
        unordered_map<char, int> word;
        for(int i=0; i<s.size(); i++)
            word[s[i]]++;
        
        for(int i=0;i<s.size();i++)
        {
            if(word[s[i]]==1)
                return i;
        }
        return -1;
    }
};
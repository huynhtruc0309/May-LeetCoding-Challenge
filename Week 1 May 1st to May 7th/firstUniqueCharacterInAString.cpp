class Solution {
public:
    int firstUniqChar(string s) { //leetcode
        int result = -1;
        unordered_map<char, int> mapS;
        if (!s.empty()) {
            for (int i = 0; i < s.size(); i++) {
                if (mapS.count(s[i]) == 0)
                    mapS[s[i]] = i;
                else 
                    mapS[s[i]] = -1;
            }
            
            int min = INT_MAX;
            for (auto it = mapS.begin(); it != mapS.end(); it++) {
                if (it->second != -1 && it->second < min) {
                    min = it->second;
                }
            }
            
            if (min != INT_MAX)
                result = min;
        }
        return result;
    }
};
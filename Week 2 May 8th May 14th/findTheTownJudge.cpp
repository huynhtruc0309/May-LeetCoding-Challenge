class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int result = -1;
        vector<int> countTrust(N, 0);
        
        for (int i = 0; i < trust.size(); i++) {
            countTrust[trust[i][0] - 1]--;  
            countTrust[trust[i][1] - 1]++; 
        }
        
        vector<int>::iterator it = find(countTrust.begin(), countTrust.end(), N-1);
        if (it != countTrust.end())
            result = (it - countTrust.begin()) + 1;
        
        return result;
    }
};
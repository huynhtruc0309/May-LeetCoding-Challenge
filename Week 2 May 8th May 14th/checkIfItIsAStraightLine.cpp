class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        bool result = true;
        
        if (coordinates.size() > 2) {
           int a1 = coordinates[1][0] - coordinates[0][0];
            int a2 = coordinates[1][1] - coordinates[0][1];
            
            for (int i = 2; i < coordinates.size(); i++) {
                int b1 = coordinates[i][0] - coordinates[0][0];
                int b2 = coordinates[i][1] - coordinates[0][1];
                
                if (a1 * b2 - a2 * b1 != 0) {
                    result = false;
                    break;
                }
            }
        }
        return result;
    }
};
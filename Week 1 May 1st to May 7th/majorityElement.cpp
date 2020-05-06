class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        int result = 0;
        
        if (!nums.empty()) {
            for (int i = 0; i < nums.size(); i++) {
                map[nums[i]] ++;
            }
            
            for (auto it = map.begin(); it != map.end(); it++) {
                if (it->second > nums.size()/2) {
                    result = it->first;
                    break;
                }
            }
        }
        return result;
    }
};
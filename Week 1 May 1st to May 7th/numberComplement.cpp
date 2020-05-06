class Solution {
public:
    int findComplement(int num) {
        int result = 0;
        int i = 0;
        
        while(num) {
            if ((num & 1) == 0)
                result += 1 << i;
            
            i += 1;
            num >>= 1;
        }
        return result;
    }
};
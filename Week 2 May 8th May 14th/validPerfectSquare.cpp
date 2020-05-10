class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 2)
            return true;

        int left = 2, right = num;
        while(left <= right) {
            long int mid = left + (right - left) / 2;
            
            if (mid * mid == num)
                return true;
            else if (mid*mid > num)
                right = mid - 1;
            else
                left = mid + 1;
        }

        return false;
    }
};
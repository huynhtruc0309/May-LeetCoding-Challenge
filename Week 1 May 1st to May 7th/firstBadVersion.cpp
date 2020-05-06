// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution { 
public:
    int firstBadVersion(int n) {
        int start = 1, end = n, mid = 0;
        
        while( start < end) {
            mid = start + (end - start)/2;
            
            if (!isBadVersion(mid))
                start = mid + 1;

            else 
                end = mid;
        }   
        
        return start;
    }
    
};
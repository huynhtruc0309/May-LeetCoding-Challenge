# First Bad Version
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

### Example:
```
Given n = 5, and version = 4 is the first bad version.

call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true

Then 4 is the first bad version. 
```
### Solution idea:
Use a dictionary (dict()):
* Save the list in a dictionary
* Re-run the loop to check if the element is already in the dictionary.
* Time: 84 ms
* Memory Usage: 16.2 MB

Runtime analysis: O(n)
``` c++
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
```
### 
# Jewels and Stones
You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".
### Example 1:
```
Input: J = "aA", S = "aAAbbbb"
Output: 3
```
### Example 2:
```
Input: J = "z", S = "ZZ"
Output: 0
```
### Note:
* S and J will consist of letters and have length at most 50.
* The characters in J are distinct.
### Hint #1
For each stone, check if it is a jewel.
### Solution
``` c++

```
# Ransom Note
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

### Note:
You may assume that both strings contain only lowercase letters.
```
canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
```
### Solution
``` c++

```
# Number Complement
Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.
### Example 1:
```
Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
```
### Example 2:
```
Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
```
### Note:
1. The given integer is guaranteed to fit within the range of a 32-bit signed integer.
2. You could assume no leading zero bit in the integer’s binary representation.
3. This question is the same as 1009: https://leetcode.com/problems/complement-of-base-10-integer/
### Solution
``` c++
```
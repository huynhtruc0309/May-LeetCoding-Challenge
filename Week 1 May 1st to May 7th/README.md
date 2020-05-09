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
Use binary search:
* Check if middle element is a bad version or not
* If middle is NOT a bad version then firstBadVersion can only lie in right half subarray after the mid element. So we recur for right half.
* Else (middle is a bad version) recur for the left half.
* Time: 0 ms
* Memory Usage: 6.1 MB

Runtime analysis: O(log(n))
``` c++
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
### Solution idea:
Use bruce force:
* Count the number of element in S is also in J
* Time: 0 ms
* Memory Usage: 6.3 MB

Runtime analysis: O(n^2)
### Solution
``` c++
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int result = 0;
        for (int i = 0; i < S.size(); i++) {
            for (int j = 0; j < J.size(); j++) {
                if (S[i] == J[j])
                    result ++;
            }
        }
        return result;
    }
};
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
### Solution idea:
Use array to store the number of each character in vocabulary:
* For magazine, we count the number of each character in magazine and store in vocab.
* For ransomNote, we check if number of each character in ransomNote is bigger than 0 in vocab
* Time: 32 ms
* Memory Usage: 8.7 MB

Runtime analysis: O(n)
### Solution
``` c++
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size())
            return false;
        if (ransomNote.size() == 0 && magazine.size() == 0)
            return true;
        
        int vocab[26] = {0};
        for (char c: magazine) 
            vocab[c-'a']++;
        
        for (char c: ransomNote) {
            if (vocab[c-'a'] == 0)
                return false;
            vocab[c-'a']--;
        }
        return true;
    }
};
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
### Solution idea:
* Time: 0 ms
* Memory Usage: 6 MB

Runtime analysis: O(n)
### Solution
``` c++
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
```
# First Unique Character in a String
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

### Examples:
```
s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
```
### Note: 
You may assume the string contain only lowercase letters.
### Solution idea:
* Time: 108 ms
* Memory Usage: 11 MB

Runtime analysis: O(n)
### Solution
```c++
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
```
# Majority Element
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

### Example 1:
```
Input: [3,2,3]
Output: 3
```
### Example 2:
```
Input: [2,2,1,1,1,2,2]
Output: 2
```
### Solution idea:
* Time: 52 ms
* Memory Usage: 19.8 MB

Runtime analysis: O(n)
### Solution
``` c++
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
```
# Cousins in Binary Tree
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.
### Example 1:
![Example 1](https://assets.leetcode.com/uploads/2019/02/12/q1248-01.png)
```
Input: root = [1,2,3,4], x = 4, y = 3
Output: false
```
### Example 2:
![Example 1](https://assets.leetcode.com/uploads/2019/02/12/q1248-02.png)
```
Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
```
### Example 2:
![Example 1](https://assets.leetcode.com/uploads/2019/02/13/q1248-03.png)
```
Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
```
### Note:
1. The number of nodes in the tree will be between 2 and 100.
2. Each node has a unique integer value from 1 to 100.
### Solution idea:
* Time: 0 ms
* Memory Usage: 11.6 MB

Runtime analysis: O(n)
### Solution
```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfsHelper(TreeNode *root, int x, int y, int depth, TreeNode *parent, vector<int> &infoDepth, vector<TreeNode *> &infoParent) {
        if (root == NULL) 
            return;
        
        if (root->val == x || root->val == y) {
            infoDepth.push_back(depth);
            infoParent.push_back(parent);
        }
        
        dfsHelper(root->left, x, y, depth + 1, root, infoDepth, infoParent);
        dfsHelper(root->right, x, y, depth + 1, root, infoDepth, infoParent);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        if (root == NULL) 
            return false;
        
        vector<int> infoDepth;
        vector<TreeNode *> infoParent;
        dfsHelper(root, x, y, 0, NULL, infoDepth, infoParent);
        
        if (infoParent[0] && infoParent[1])
            return (infoDepth[0] == infoDepth[1]) && (infoParent[0] != infoParent[1]);
        else
            return false;
        
    }
};
```
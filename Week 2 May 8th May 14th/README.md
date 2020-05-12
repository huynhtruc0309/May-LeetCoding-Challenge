# Check If It Is a Straight Line
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.
### Example 1:
![Example 1](https://assets.leetcode.com/uploads/2019/10/15/untitled-diagram-2.jpg)
```
Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true
```
### Example 2:
![Example 2](https://assets.leetcode.com/uploads/2019/10/09/untitled-diagram-1.jpg)
```
Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false
```
### Constraints:
* 2 <= coordinates.length <= 1000
* coordinates[i].length == 2
* -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
* coordinates contains no duplicate point.
### Hint #1
If there're only 2 points, return true.
### Hint #2
Check if all other points lie on the line defined by the first 2 points.
### Hint #3
Use cross product to check collinearity.
### Solution idea:
* Use cross product to check collinearity
* Time: 20 ms
* Memory Usage: 10.2 MB

Runtime analysis: O(n)
### Solution
```c++
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
```
# Valid Perfect Square
Given a positive integer num, write a function which returns True if num is a perfect square else False.

### Note: 
Do not use any built-in library function such as sqrt.

### Example 1:
```
Input: 16
Output: true
```
### Example 2:
```
Input: 14
Output: false
```
### Solution idea:
Use binary search to find the number squared to num
* Time: 0 ms
* Memory Usage: 5.9 MB

Runtime analysis: O(log(n))
### Solution
``` c++
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
```
# Find the Town Judge
In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.

If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.
### Example 1:
```
Input: N = 2, trust = [[1,2]]
Output: 2
```
### Example 2:
```
Input: N = 3, trust = [[1,3],[2,3]]
Output: 3
```
### Example 3:
```
Input: N = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1
```
### Example 4:
```
Input: N = 3, trust = [[1,2],[2,3]]
Output: -1
```
### Example 5:
```
Input: N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
Output: 3
```
### Note:
* 1 <= N <= 1000
* trust.length <= 10000
* trust[i] are all different
* trust[i][0] != trust[i][1]
* 1 <= trust[i][0], trust[i][1] <= N
### Solution idea
For each person, counting the number of trust and be trusted by others. 

If the i-person is believed, then their countTrust will increase by 1. 

On the the other hand, if they believe in another person, the countTrust will be reduced by 1. 

The Town Judge is the person who has countTrust equal N-1 with N is the number of people in Town.

* Runtime: 360 ms
* Memory Usage: 60.7 MB

Runtime analysis: O(n)
### Solution
``` c++
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
``` 
# Flood Fill
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.
### Example 1:
```
Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.
```
### Note:
* The length of image and image[0] will be in the range [1, 50].
* The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
* The value of each color in image[i][j] and newColor will be an integer in [0, 65535].
### Hint #1  
Write a recursive function that paints the pixel if it's the correct color, then recurses on neighboring pixels.
### Solution idea
* Runtime: 12 ms
* Memory Usage: 14.1 MB
### Solution
```c++
class Solution {
public:
    void floodFillHelper(vector<vector<int>>& image, int sr, int sc, int newColor, int posColor) {
        if (image.size()) {
            if (sr >= image.size() || sr < 0 || sc >= image[0].size() || sc < 0 || image[sr][sc] != posColor || image[sr][sc] == newColor) 
                return;
            
            image[sr][sc] = newColor;
            //Up
            floodFillHelper(image, sr - 1, sc, newColor, posColor);
            //Left
            floodFillHelper(image, sr, sc - 1, newColor, posColor);
            //Right
            floodFillHelper(image, sr, sc + 1, newColor, posColor);
            //Down
            floodFillHelper(image, sr + 1, sc, newColor, posColor);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image.size()) {
            if (sr >= image.size() || sr < 0 || sc >= image[0].size() || sc < 0) 
                return image;
            
            floodFillHelper(image, sr, sc, newColor, image[sr][sc]);
        }
        
        return image;
    }
};
```

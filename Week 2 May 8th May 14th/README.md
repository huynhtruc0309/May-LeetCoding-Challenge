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

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
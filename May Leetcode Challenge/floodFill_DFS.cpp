/* 
Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, 
and a pixel value newColor, "flood fill" the image.
To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel 
of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color 
as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.

Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2

Output: [[2,2,2],[2,2,0],[2,0,1]]

*/

void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int rows, int cols, int source)
{
    if(sr < 0 || sr >= rows || sc < 0 || sc >= cols)
        return;
    
    else if(image[sr][sc] != source)
        return;
    
    // If thats not the case means value at sr and sc and the source are same.
    // We change that value with newColor.
    
    image[sr][sc] = newColor;
    // If value at that coordinate and source are same then we perform recursive calls
    // in all the four directions.
    
    dfs(image,sr-1,sc,newColor,rows,cols,source); // Top
    dfs(image,sr+1,sc,newColor,rows,cols,source); // Bottom
    dfs(image,sr,sc-1,newColor,rows,cols,source); // Left
    dfs(image,sr,sc+1,newColor,rows,cols,source); // Right
    
}


vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
{
    
    if(image[sr][sc] == newColor) // If newColor and current position value are same
        return image;             // we can safely return since values won't change.
    
    int m = image.size();
    int n = image[0].size();
    
    int source = image[sr][sc]; // Assign source current position's value
    
    dfs(image,sr,sc,newColor,m,n,source);
    
    return image;
}

// Time Complexity: O(m * n);
// Spcae: O(1)
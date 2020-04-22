/* Question:
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

Eg: 

Input:
11000
11000
00100
00011

Output: 3
*/

void mark_current_island(vector<vector<char>> &matrix,int x, int y, int row, int col)
{
    // we have matrix and (x,y) as current coordinates and rows and cols
    
    if(x<0 || x >= row || y < 0 || y >= col || matrix[x][y] != '1')
        return;
    
    // if we don't have any corner cases then we mark is as visited i.e 2
    matrix[x][y] = '2';
    
    // now we recursively go in horizontal and vertical directions to find of we have land
    // i.e '1'.
    
    mark_current_island(matrix, x+1, y, row, col); // down
    mark_current_island(matrix, x-1, y, row, col); // top
    mark_current_island(matrix, x, y+1, row, col); // right
    mark_current_island(matrix, x, y-1, row, col); // left

}

int numIslands(vector<vector<char>>& grid) 
{
    
    int row = grid.size();
    
    if(row==0)
        return 0;
    
    int col = grid[0].size();
    int no_of_islands = 0;
    
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(grid[i][j] == '1') // since we have a matrix of type char
            {
                mark_current_island(grid,i,j,row,col);
                no_of_islands++;
            }
        }
    }

    return no_of_islands;
    
}

// Time complexity -  O(n)
// space complexity - O(1) if we do not consider stack memory while recusive calls for space analysis
//                   else its O(row*col*space by stack)
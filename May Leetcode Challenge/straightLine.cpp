/* 
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. 
Check if these points make a straight line in the XY plane.

Eg: 
Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true
Note: Coordinates contains no duplicate point.

    bool collinear(int x1, int y1, int x2, int y2, int x3, int y3) 
    {
        return (y1 - y2) * (x1 - x3) == (y1 - y3) * (x1 - x2); 
        
        // We don't use division since to avoid division by zero problem. when(x2 == x1).
    } 
*/
    
bool checkStraightLine(vector<vector<int>>& coordinates) 
{
    
    int m = coordinates.size();
    
    int xdiff = coordinates[1][0] - coordinates[0][0];
    int ydiff = coordinates[1][1] - coordinates[0][1];
    
    // int slope = (y2 - y1) / (x2 - x1); this way it may lead to division by zero problem
    
    int curr_xdiff,curr_ydiff;
    
    for(int i=2;i<m;i++)
    {
        curr_xdiff = coordinates[i][0] - coordinates[i-1][0];
        curr_ydiff = coordinates[i][1] - coordinates[i-1][1];
        
        if(xdiff * curr_ydiff != ydiff * curr_xdiff) // main condition of collinearity.
            return false;
    }
    
    return true;
}

// Time Complexity: O(n)
// Space: O(1)
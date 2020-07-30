/* Problem: The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that 
         no two queens attack each other.

Solution: In this problem, we can go row by row, and in each position, 
we need to check if the column, the 45° diagonal and the 135° diagonal had a queen before.
As simple as taht this problem boils down to these 3 cases which are easier to handle.

*/

// Lets check if the positon we wanna keep the queen is valid one:

bool isValid(vector<string> &nQueens, int row, int col, int &n) 
{
        //check if the column had a queen before.
    for (int i = 0; i != row; ++i)
        if (nQueens[i][col] == 'Q')
            return false;
    //check if the 135° diagonal had a queen before.
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
        if (nQueens[i][j] == 'Q')
            return false;
    //check if the 45° diagonal had a queen before.
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
        if (nQueens[i][j] == 'Q')
            return false;
    return true;
}

void solvingNQueens(vector<vector<string>>& result, vector<string>& nQueens, int row, int &n)
{
    if(row == n)
    {
        result.push_back(nQueens);
        return;
    }
    
    for(int col=0;col<n;col++)
    {
        if(isValid(nQueens,col,row,n)) // if position is valid
        {
            nQueens[row][col] = 'Q'; // place queen at this particular col 
            solvingNQueens(result, nQueens, row+1,n); // check for other rows
            
            // backtrack
            nQueens[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) 
{
    
    vector<vector<string>> result;
    
    vector<string> nQueens(n, string(n,'.'));
    
    solvingNQueens(result,nQueens,0,n);
    
    return result;
}

// Time: O(n^2), we are checking every row and col and backtraking if not found result.

// Space: O(n^2), we need a result matrix
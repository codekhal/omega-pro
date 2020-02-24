#include <bits/stdc++.h>
using namespace std;

bool issafe(int maze[n][n],int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<n && maze[x][y] == 1)
        return true;
    return false;
}

bool solveUtil(int maze[n][n],int x,int y,int sol[n][n])
{
    if (x == n-1 && y == n-1) {
        sol[x][y] = 1;
        return true;
    }

    if(issafe(maze,x,y) == true) {
        sol[x][y] = 1;
        if (solveUtil(maze,x+1,y,sol)) {
            return true;
        }
        if (solveUtil(maze,x,y+1,sol)) {
            return true;
        }

        sol[x][y] = 0;
        return false;
    }
    return false;

    
}
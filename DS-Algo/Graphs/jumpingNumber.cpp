// A number is called as a jumping Number if all adjacent digits in it differ by 1
// A jump number must consists of a jump number *10 + the right most digit of the jump number + or - 1 (corner case exception)
// Time Complexity: O(x) where x is the number of jumping numbers.
// Simple Solution: A simple solution would be to traverse through all the numbers less than equal to that number and check if 
//                  number is jumping or not.

// Efficient solution: Using BFS/DFS traverse the node of the graph.

#include<bits/stdc++.h>
using namespace std;

void bfs(int x, int num) 
{ 
    queue<int> q; 
    q.push(num); 
  
    while (!q.empty()) { 
        num = q.front(); 
        q.pop(); 
  
        if (num <= x) { 
            cout << num << " "; 
            int last_dig = num % 10; 

            if (last_dig == 0) 
                q.push((num * 10) + (last_dig + 1)); 
  
            else if (last_dig == 9) 
                q.push((num * 10) + (last_dig - 1)); 

            else { 
                q.push((num * 10) + (last_dig - 1)); 
                q.push((num * 10) + (last_dig + 1)); 
            } 
        } 
    } 
} 

void printjumpingnumbers(int x)
{
    cout << 0 << " ";
    for (int i = 1; i <= 9 && i <= x; i++) 
        bfs(x, i);
}

int main()
{
	int n;
	cin >> n;
	printjumpingnumbers(n);
	return 0;
}
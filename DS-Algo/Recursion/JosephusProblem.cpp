// Given n people and kth position, we have to kill every kth person such that only one peron remains last survivor.

#include <bits/stdc++.h> 
using namespace std;  

int josephus(int n, int k) 
{ 
  if (n == 1)  // Base Case, if only one person is remaining that is our survivor.
    return 1; 
  else
                /* The position returned by josephus(n - 1, k) is adjusted because the 
                recursive call josephus(n - 1, k) considers the original position  
                k % n + 1 as position 1. Since in a circle we need to add k to the recursive 
                term since our (k-1)th position is now nth position and (k+1)th position
                is 1st position. adding k-1 and 1 at the end is because if rec() + k % n == 0 
                then we have to remove that case as well.*/
    return (josephus(n - 1, k) + k-1) % n + 1; 
} 
  
// Driver Program to test above function 
int main() 
{ 
  int n = 14; 
  int k = 2; 
  cout<<"The place Chosen is "<< josephus(n, k); 
  return 0; 
} 
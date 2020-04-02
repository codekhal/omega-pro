
int fun(int n) 
{ 
  int count = 0; 
  for (int i = n; i > 0; i /= 2) 
     for (int j = 0; j < i; j++) 
        count += 1; 
  return count; 
} 

// Ans: O(n)

// Solution: 

// For a input integer n, the innermost statement of fun() is executed following times.

// n + n/2 + n/4 + … 1


// So time complexity T(n):

// T(n) = O(n + n/2 + n/4 + … 1) = O(n)
// We can get this by substituting values into formula of Sum of GP. We shall get 2n-1 which is O(n).
// The value of count is also n + n/2 + n/4 + .. + 1
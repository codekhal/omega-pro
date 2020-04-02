### Some important points:

- Θ(n) has higher growth than Θ(Logn * Logn), f1(n) grows faster than f4(n). Where: f1(n) = 2^n,  f4(n) = n^(Logn)

- Applying binary search to calculate the position of the data to be inserted doesn't reduce the time complexity of insertion sort.

- Time Complexity of following loops:

A) for(i = 0; i < n; i++)       : Time Complexity of first for loop is O(n).

B) for(i = 0; i < n; i += 2)    : Time Complexity of first for loop is O(n/2), equivalent to O(n) in asymptotic analysis.

C) for(i = 1; i < n; i *= 2)    : Time Complexity of first for loop is O(logn).

- If a function is recursively called and added in a variable, space complexity is not O(1) in this case. Space complexity is O(n) as there can be at most O(n) active functions.

- Randomized quicksort has expected time complexity as O(nLogn), but worst case time complexity remains same. In worst case the randomized function can pick the index of corner element every time.

- Stirling’s approximation: log n! = n log n - n + O(log(n)) i.e., O(log n!) = O(n log n).

- Given A, an array of size n, comprised of an increasing sequence of numbers followed immediately by a decreasing one:  application of Binary search therefore, O(logn).

- A sorting technique is called stable if: It maintains the relative order of occurrence of non-distinct elements.
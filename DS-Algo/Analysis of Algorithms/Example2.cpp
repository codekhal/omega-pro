
void fun(int n, int arr[]) 
{ 
    int i = 0, j = 0; 
    for(; i < n; ++i) 
        while(j < n && arr[i] < arr[j]) 
            j++; 
} 

// Ans: O(n)

// Solution: 
// In the first look, the time complexity seems to be O(n^2) due to two loops. 
// But, please note that the variable j is not initialized for each value of variable i. 
// So, the inner loop runs at most n times. 
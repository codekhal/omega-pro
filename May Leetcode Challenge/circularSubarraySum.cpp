/* Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C

Input: [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3

*/

// Kadane's algorithm is used to find the maximum subarray sum
    
int maxSubarraySumCircular(vector<int>& A) 
{
    
    int n = A.size();
    
    int maxEndingHere = 0;
    int minEndingHere = 0;
    int minsum = INT_MAX;
    int maxsum = INT_MIN;
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        sum += A[i];    
        maxEndingHere = max(maxEndingHere+A[i],A[i]);
        maxsum = max(maxsum,maxEndingHere);
        minEndingHere = min(minEndingHere+A[i],A[i]);
        minsum = min(minsum,minEndingHere);
        
    }
    
    if(maxsum > 0)
    {
        return max(maxsum, sum - minsum);
    }
    
    return maxsum;
}

// Time Complexity: O(n)